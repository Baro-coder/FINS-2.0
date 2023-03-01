# **`FINS`**

## **FLORA Inertial Navigation System**

---

## **Description**

This project involes developing the real time <u>*Dead Reckoning*</u> system implementation to UAV ob-board module. 

It can be a good support navigation system in GNSS-denied or GPS-denied enviroment.

In cooperation with others offline navigation systems, like *VNS* (Visual Navigation Systems), it will be able to replace GPS-based navigation systems using by UAVs.

---

## **Instalation**

The installation guide is adapted to Linux family OS. The project was being developed on Ubuntu 22.04 OS.

### Required versions:

| Module    | Version |
|:-----     |   -----:|
|**Python** | `3.10`  |
|**pip**    | `22.0`  |
|**g++**    | `11.3`  |
|**gcc**    | `11.3`  |

---

### 1. Clone this repository:

```console
git clone https://github.com/Baro-coder/FINS-2.0
```

### 2. Move to directory:

```console
cd FINS
```

### 3. Make sure you meet the version requirements stated above:

3.1. Python:
```console
python -V ; pip -V
```

3.2. gcc / g++:
```
gcc --version ; g++ --version
```

### 4. Create Python virtual enviroment:

4.1. Install python virtual enviroment module:
```console
python -m pip install virtualenv
```

4.2 Create virtual enviroment for this project:
```console
python -m venv ./.venv
```

4.3. Switch Python interpreter to created one:
```console
source ./.venv/bin/activate
```

### 5. Install required Python modules:

```console
python -m pip install -r requirements.txt
```

### 6. Compile all C/C++ sources:

```console
make
```

---

### Project is ready to work. Now you can execute any shell scripts from `FINS/bin`

Example:
```console
./bin/graph-gen.sh
```

---

## **Structure**

``` text
FINS
├── bin                     'Main bash binaries'
│
├── data                    'Data Directory'
│   ├── proc                    'Processed data'
│   ├── norm                    'Normalized data'
│   ├── raw                     'Raw data'
│   └── tlogs                   'ArduPilot tlogs'
│
├── fins-cpp                'C++ project directory'
│   ├── bin                     'binaries'
│   ├── lib                     'liraries'
│   └── src                     'sources'
│
├── fins-py                 'Python project directory'
│   └── tools                   'Diagnostic tools'
│       ├── comparators             'Datasets comparators'
│       ├── graphs                  'Graphs generators'
│       └── map                     'Maps visualizers'
│
└── img                     'Images'

```

### [**`bin`**](https://github.com/Baro-coder/FINS-2.0/tree/master/bin)

Main bash scripts to executing complex functions using developed scripts and programs with provided data.

---

### [**`data`**](https://github.com/Baro-coder/FINS-2.0/tree/master/data)

Data collected from UAVs logs.

- `proc` : Processed CSV data
- `norm` : Normalized CSV data
- `raw`  : Raw CSV data
- `tlog` : ArduPilot *.tlog* files

---

### [**`fins-cpp`**](https://github.com/Baro-coder/FINS-2.0/tree/master/fins-cpp)

#### **C++ project directory**

Project includes compute module software to estimate UAV velocity using UAV inertial data and to calculate current position coordinates (latitude, longitude) using previous position, course (heading) and previously estimated velocity.

---

### [**`fins-py`**](https://github.com/Baro-coder/FINS-2.0/tree/master/fins-py)

#### **Python project directory**

Project includes datasets comparators and visualizers.

---

### [**`img`**](https://github.com/Baro-coder/FINS-2.0/tree/master/img)

#### **Images directory**

Directory includes example graphs, maps and other complex outputs.
