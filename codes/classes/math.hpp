#ifndef MATH_HPP
#define MATH_HPP

struct v2 {
    float x;
    float y;

    static v2 Zero() {
        return {0, 0};
    }

    v2 operator+(v2 other) {
        return {x + other.x , y + other.y};
    }
    
    v2 operator*(float value) {
        return {x * value, y * value};
    }

    void operator+=(v2 other) {
        x += other.x;
        y += other.y;
    }
};

struct AABB {
    union {
        struct {
            float x0;
            float y0;
        };
        v2 min;
    };
    union {
        struct {
            float x1;
            float y1;
        };
        v2 max;
    };

    AABB() = default;
    AABB(v2 position, v2 size) {
        Update(position, size);
    }
    void Update(v2 position, v2 size) {
        min = position;
        max = min + size; 
    }

    v2 GetSize() {
        return {x1 - x0, y1 - y0};
    }

    static bool Intersects(AABB a, AABB b){
        bool xAxisCheck = a.x1 >= b.x0 && a.x0 <= b.x1;
        bool yAxisCheck = a.y1 >= b.y0 && a.y0 <= b.y1;

        return xAxisCheck && yAxisCheck;
    }
};
#endif //MATH_HPP
