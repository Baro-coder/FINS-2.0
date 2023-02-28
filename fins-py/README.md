# **`FINS Python`**

## **Description**

Directory includes python diagnostic tools which can be valuable in project development process, for example: graphs generators, map paths visualizers, datasets comparators and others.

---

## **Programs**

## Graphs

### **`graph_cmp.py`**

**Description**

Python graph compare tool to set up two similar datasets as a graphs at single figure.
Similar datasets means datasets of the same datatype, for example: accelerometer data and filtered accelerometer data.

**Positional arguments:**
- 1<sup>st</sup> dataset csv filepath
- 2<sup>nd</sup> dataset csv filepath

**Usage example:**

``` text
python ./fins-py/tools/graphs/graph_cmp.py ./data/norm/acc.csv ./data/proc/acc.csv
```

**Example output**

> Not generated yet ...

---

### **`graph_def.py`**

**Description**

Python default graph tool to visualize csv data from specified files: each file at its own figure. First column is the axis X values set, and the following columns are separated axis Y values sets.

**Positional arguments:**
- 1<sup>st</sup> dataset csv filepath
- 2<sup>nd</sup> dataset csv filepath
- *n*<sup>th</sup> dataset csv filepath

**Usage example:**

``` text
python ./fins-py/tools/graphs/graph.py ./data/norm/acc.csv ./data/norm/gyro.csv ./data/norm/alt.csv
```

**Example output**

<img src="https://raw.githubusercontent.com/Baro-coder/FINS-2.0/develop/img/example_graph_def.png" width=80% height=80%>

---

### **`graph_gps.py`**

**Description**

Python GPS graph tool to visualize GPS data (lattitude and longitude) at the same figure but with separated scales.

**Positional arguments:**
- GPS dataset csv filepath
- 2<sup>nd</sup> GPS dataset (<u>*Optional*</u>)

**Usage example:**

``` text
python ./fins-py/tools/graphs/graph_gps.py ./data/norm/gps.csv
```

***OR***

``` text
python ./fins-py/tools/graphs/graph_gps.py ./data/norm/gps.csv ./data/proc/gps.csv
```

**Example output**

*Ex. 1*

<img src="https://raw.githubusercontent.com/Baro-coder/FINS-2.0/develop/img/example_graph_gps.png" width=60% height=60%>

*Ex. 2*

> Not generated yet ...


---


### **Comparators**

> Not implemented yet ...


---


### **Map**

> Not implemented yet ...

---


