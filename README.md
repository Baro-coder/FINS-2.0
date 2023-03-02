# **FLORA Inertial Navigation System**

## **Project Description**

This project involes developing the real time <u>*Dead Reckoning*</u> system implementation to **UAV on-board component** and *tlog* data analysis **console app**.

It can be a good support navigation system in <u>**GNSS/GPS-denied**</u> enviroment.

In cooperation with others offline navigation systems, like **VNS** (Visual Navigation Systems), it will be able to replace GPS-based navigation systems using by UAVs.

---

## **Console App**

## Installation

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
```console
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
./bin/fins.sh
```

---

## Description

> TODO ...

---

## Structure

> TODO ...

---

## Usage

> TODO ...

---

## **UAV on-board electronic component**

## Description

> TODO ...

---

## Circuit schema

> TODO ...

---

## Communication

> TODO ...

---
