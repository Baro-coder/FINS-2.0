import sys
import pandas as pd
import matplotlib.pyplot as plt

def single_file(t : list, lat : list, lon : list, title : str) -> None:
    fig, ax1 = plt.subplots()
    
    ax1.set_title(title)

    color = 'tab:orange'
    ax1.set_xlabel('time')
    ax1.set_ylabel('Lattitude', color=color)
    ax1.plot(t, lat, color=color)
    ax1.tick_params(axis='y', labelcolor=color)

    ax2 = ax1.twinx()

    color = 'tab:blue'
    ax2.set_ylabel('Longitude', color=color)
    ax2.plot(t, lon, color=color)
    ax2.tick_params(axis='y', labelcolor=color)
    
    fig.tight_layout()

def two_files(t : list, lats : list, lons : list, title : str) -> None:
    fig, ax1 = plt.subplots()

    ax1.set_title(title)

    color1 = 'tab:orange'
    color2 = 'tab:red'

    ax1.set_xlabel('time')
    ax1.set_ylabel('Lattitude')
    ax1.plot(t, lats[0], color=color1, label='Lat-1')
    ax1.plot(t, lats[1], color=color2, label='Lat-2')
    ax1.legend(loc='upper left')

    ax2 = ax1.twinx()

    color1 = 'tab:blue'
    color2 = 'tab:purple'

    ax2.set_ylabel('Longitude')
    ax2.plot(t, lons[0], color=color1, label='Lon-1')
    ax2.plot(t, lons[1], color=color2, label='Lon-2')
    ax2.legend(loc='upper right')

    fig.tight_layout()

def main() -> None:
    # Pos Args check
    if len(sys.argv) not in (2, 3):
        print('Incorrect usage! Pass the csv filepath.')
        print('Usage example:')
        print(f'    python {sys.argv[0]} ./data/gps_data.csv')
        print(f'    python {sys.argv[0]} ./data/gps_data.csv ./data/gps_data_2.csv')
        sys.exit(1)

    if len(sys.argv) == 2:
        # Single File
        fpath = sys.argv[1]
        print(f'File: {fpath} : ', end='')
    
        try:
            # Try to open given file and read content
            df = pd.read_csv(fpath)
            print('Loaded.')

        except FileNotFoundError as e:
            print('Not Found!')
            sys.exit(1)

        t = df[df.keys()[0]].to_list()
        lat = df[df.keys()[1]].to_list()
        lon = df[df.keys()[2]].to_list()
        title = fpath

        single_file(t, lat, lon, title)

    elif len(sys.argv) == 3:
        # Two Files
        fpaths = [sys.argv[1], sys.argv[2]]
        dfs = []

        try:
            # Try to open given files and read content
            for path in fpaths:
                print(f'File: {path} : ', end='')
                df = pd.read_csv(path)
                dfs.append(df)
                print('Loaded.')

        except FileNotFoundError as e:
            print('Not Found!')
            sys.exit(1)

        t = dfs[0][df.keys()[0]].to_list()
        lats = []
        lons = []

        for df in dfs:
            lat = df[df.keys()[1]].to_list()
            lon = df[df.keys()[2]].to_list()
            lats.append(lat)
            lons.append(lon)

        title = 'GPS Comparison'

        two_files(t, lats, lons, title)

    plt.show()

    sys.exit(0)


if __name__ == '__main__':
    main()