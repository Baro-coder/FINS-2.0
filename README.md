# `FINS`

## `FLORA Inertial Navigation System`

---

## **Description**

This project involes developing the real time <u>*Dead Reckoning*</u> system implementation to UAV ob-board module. 

It can be a good support navigation system in GNSS-denied or GPS-denied enviroment.

In cooperation with others offline navigation systems, like *VNS* (Visual Navigation Systems), it will be able to replace GPS-based navigation systems using by UAVs.

---

## **Structure**

``` text
FINS/
├── data
│   ├── calc
│   ├── norm
│   ├── raw
│   └── tlogs
│
├── fins-cpp
│   ├── bin
│   ├── lib
│   ├── Makefile
│   └── src
│
└── fins-py
    ├── fins
    │   ├── conf
    │   └── log
    └── fins.py
```

### **Data** 

Data collected from UAVs logs.

- `calc` : Calculated CSV data
- `norm` : Normalized CSV data
- `raw`  : Raw CSV data
- `tlog` : Original *.tlog* files

### **fins-cpp**

#### C++ project directory.

Project includes compute module software to estimate UAV velocity using UAV inertial data and to calculate current position coordinates (latitude, longitude) using previous position, course (heading) and previously estimated velocity.

### **fins-py**

Python project directory.

Project includes reading data files, data normalization and visualization using plots and map paths.

---

