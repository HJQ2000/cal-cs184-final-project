vector<Color> uv_checkers(int width, int height, Color color_a, Color color_b) {
    Color col = Color(width, height, 0);
    vector<Color> retvec = vector<Color>();
    retvec.push_back(color_a);
    retvec.push_back(color_b);
    retvec.push_back(Color(width, height, 0));
    return retvec;
}

Color uv_pattern_at(vector<Color> checkers, float u, float v) {
    Color color_a = checkers[0];
    Color color_b = checkers[1];
    float width = checkers[2][0];
    float height = checkers[2][1];
    int testnum = floor(u * width) + floor(v * height);
    if (testnum % 2 == 0) {
        return color_a;
    }
    else {
        return color_b;
    }
}

Vector2D spherical_map(Vector3D p) {
    double theta = atan2(p.x, p.z);
    double radius = p.norm();
    double phi = acos(p.y / radius);
    double raw_u = theta / (2 * PI);
    double u = 1 - (raw_u + 0.5);
    double v = 1 - phi / PI;
    return Vector2D(u, v);
}

struct TextureMap {
    vector<Color> uv_pattern;
    function<Vector2D(Vector3D)> uv_map;

    TextureMap(vector<Color> p, function<Vector2D(Vector3D)> m);
};

TextureMap::TextureMap(vector<Color> p, function<Vector2D(Vector3D)> m) {
    uv_pattern = p;
    uv_map = m;
}

TextureMap texture_map(vector<Color> uv_pattern, function<Vector2D(Vector3D)> uv_map) {
    return TextureMap(uv_pattern, uv_map);
}


Color pattern_at(TextureMap tex, Vector3D p) {
    Vector2D uv = tex.uv_map(p);
    return uv_pattern_at(tex.uv_pattern, uv[0], uv[1]);
}