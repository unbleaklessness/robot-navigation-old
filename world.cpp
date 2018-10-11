#include "world.h"

#include "shape.h"

vector1 world::make_room_1(int room_width, int room_height) {
    vector1 room;

    const int wall_size = 20;

    auto top_wall = shape::make_rectangle(0, room_height - wall_size, room_width, wall_size);
    room.insert(room.end(), top_wall.begin(), top_wall.end());

    auto left_wall = shape::make_rectangle(0, wall_size, wall_size, room_height - (wall_size * 2));
    room.insert(room.end(), left_wall.begin(), left_wall.end());

    auto right_wall = shape::make_rectangle(room_width - wall_size, wall_size, wall_size, room_height - (wall_size * 2));
    room.insert(room.end(), right_wall.begin(), right_wall.end());

    auto bottom_wall = shape::make_rectangle(0, 0, room_width, wall_size);
    room.insert(room.end(), bottom_wall.begin(), bottom_wall.end());

    auto bottom_separator = shape::make_rectangle((room_width / 2) - wall_size, wall_size, wall_size, room_height / 100 * 35);
    room.insert(room.end(), bottom_separator.begin(), bottom_separator.end());

    auto top_separator = shape::make_rectangle((room_width / 2) - wall_size, room_height - (room_height / 100 * 35) - wall_size, wall_size, room_height / 100 * 35);
    room.insert(room.end(), top_separator.begin(), top_separator.end());

    auto left_box = shape::make_rectangle(room_width / 100 * 15, room_height / 100 * 35, room_width / 100 * 20, room_height / 100 * 30);
    room.insert(room.end(), left_box.begin(), left_box.end());

    auto right_box = shape::make_rectangle(room_width / 100 * 65, room_height / 100 * 35, room_width / 100 * 20, room_height / 100 * 30);
    room.insert(room.end(), right_box.begin(), right_box.end());

    return room;
}

vector1 world::make_room_2(int room_width, int room_height) {
    vector1 room;

    const int wall_size = 1;

    auto top_wall = shape::make_rectangle(0, room_height - wall_size, room_width, wall_size);
    room.insert(room.end(), top_wall.begin(), top_wall.end());

    auto left_wall = shape::make_rectangle(0, wall_size, wall_size, room_height - (wall_size * 2));
    room.insert(room.end(), left_wall.begin(), left_wall.end());

    auto right_wall = shape::make_rectangle(room_width - wall_size, wall_size, wall_size, room_height - (wall_size * 2));
    room.insert(room.end(), right_wall.begin(), right_wall.end());

    auto bottom_wall = shape::make_rectangle(0, 0, room_width, wall_size);
    room.insert(room.end(), bottom_wall.begin(), bottom_wall.end());

    auto circle = shape::make_circle(150, 250, 50);
    room.insert(room.end(), circle.begin(), circle.end());

    auto square = shape::make_rectangle(70, 70, 60, 60);
    room.insert(room.end(), square.begin(), square.end());

    auto rect = shape::make_rectangle(280, 100, 40, 150);
    room.insert(room.end(), rect.begin(), rect.end());

    return room;
}

vector1 world::room_2::make_walls() {
    vector1 walls;

    auto top_wall = shape::make_rectangle(0, 399, 400, 1);
    walls.insert(walls.end(), top_wall.begin(), top_wall.end());

    auto bottom_wall = shape::make_rectangle(0, 0, 400, 1);
    walls.insert(walls.end(), bottom_wall.begin(), bottom_wall.end());

    auto left_wall = shape::make_rectangle(0, 1, 1, 398);
    walls.insert(walls.end(), left_wall.begin(), left_wall.end());

    auto right_wall = shape::make_rectangle(399, 1, 1, 398);
    walls.insert(walls.end(), right_wall.begin(), right_wall.end());

    return walls;
}

vector1 world::room_2::make_rectangle() {
    return shape::make_rectangle(280, 100, 40, 150);
}

vector1 world::room_2::make_square() {
    return shape::make_rectangle(70, 70, 60, 60);
}

vector1 world::room_2::make_circle() {
    return shape::make_circle(150, 250, 50);
}