# My_Radar

## Overview

My_Radar is a 2D air traffic simulation game that visualizes air traffic control systems. Players manage aircrafts and control towers, ensuring safe navigation and avoiding collisions, with special rules within control tower areas.

## Game Rules

- Aircrafts fly from set points to destinations, appearing when taking off and disappearing upon landing.
- Aircrafts move in a straight line at constant speeds.
- Collisions lead to destruction, except within control tower areas.
- Control Towers have control areas and are static.

## Features

- **Interactive Menu:** Start or quit the game through a user interface.
- **Real-time Timer:** Tracks simulation duration.
- **Aircraft Tracking:** Real-time display of active, departed, and arrived aircrafts.
- **Key Controls:**
  - **L:** Toggle hitboxes and areas.
  - **S:** Show/Hide sprites.
  - **P:** Pause/Resume.

## Tools Required

- **SFML:** For graphics and input handling.
- **C Compiler (GCC):** For compiling source code.

## Installation and Running the Game

1. **Clone and Navigate:**

    ```bash
    git clone git@github.com:Haloys/my_radar.git
    cd my_radar
    ```

2. **Compile:**

    ```bash
    make
    ```

3. **Launch Game:**

    ```bash
    ./my_radar script/test.rdr
    ```

## Script Generation

`.rdr` scripts define aircraft and tower setups. A Python script generates these files:

## Genererate a Script:

- Default filename (creates **`simulation.rdr`**):

```bash
python script.py --towers 5 --planes 10000
```

Output: **`Simulation file 'simulation.rdr' generated with 5 towers and 10000 planes.`**
- Specifying filename without **`.rdr`** (not recommended, but possible):

```bash
python script.py --towers 5 --planes 10000 --filename test
```

- Recommended usage with **`.rdr`**:

```bash
python script.py --towers 5 --planes 10000 --filename test.rdr
```

## Screen Size and Parameters

- Runs on 1920x1080 screen.
- Adjustable tower and aircraft parameters in scripts.
- Screen size can be resized to fit your monitor, but this is not recommended for optimal gameplay experience.
