import random
import argparse

def generate_towers(num_towers, radius_range, screen_size):
    towers = []
    for _ in range(num_towers):
        x = random.randint(0, screen_size[0])
        y = random.randint(0, screen_size[1])
        radius = random.randint(radius_range[0], radius_range[1])
        towers.append(f"T {x} {y} {radius}")
    return towers

def generate_random_coordinates(screen_size):
    x = random.randint(0, screen_size[0])
    y = random.randint(0, screen_size[1])
    return x, y

def generate_planes(num_planes, screen_size, speed_range, delay_range):
    planes = []
    for _ in range(num_planes):
        start_x, start_y = generate_random_coordinates(screen_size)
        end_x, end_y = generate_random_coordinates(screen_size)
        speed = random.randint(speed_range[0], speed_range[1])
        delay = random.randint(delay_range[0], delay_range[1])
        planes.append(f"A {start_x} {start_y} {end_x} {end_y} {speed} {delay}")
    return planes

def save_to_file(filename, towers, planes):
    with open(filename, 'w') as file:
        for tower in towers:
            file.write(tower + '\n')
        for plane in planes:
            file.write(plane + '\n')

def main():
    parser = argparse.ArgumentParser(description='Generate a simulation file for air traffic control.')
    parser.add_argument('--towers', type=int, default=5, help='Number of towers to generate')
    parser.add_argument('--planes', type=int, default=10, help='Number of planes to generate')
    parser.add_argument('--filename', type=str, default='simulation.rdr', help='Output filename')
    args = parser.parse_args()

    screen_size = (1920, 1080)  # Width, Height
    radius_range = (5, 15)  # Min, Max radius
    speed_range = (15, 300)  # Min, Max speed
    delay_range = (0, 15)  # Min, Max delay

    towers = generate_towers(args.towers, radius_range, screen_size)
    planes = generate_planes(args.planes, screen_size, speed_range, delay_range)
    save_to_file(args.filename, towers, planes)

    print(f"Simulation file '{args.filename}' generated with {args.towers} towers and {args.planes} planes.")

if __name__ == '__main__':
    main()
