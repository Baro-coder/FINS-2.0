import sys
import pandas as pd
import matplotlib.pyplot as plt

'''
    Description:
        Program to draw plots by data from csv files.
        All data are scaled to ``ITS OWN`` Y axis scale.
        
    Params:
        <datafilepath> : Path to csv file with data to visualization.
                            It is available to pass multiple paths.
                            
    Example:
        python plot_scale_multi.py ./data/data1.csv ./data/data2.csv ./data/org/dataorg1.csv
        
'''

def main() -> None:
    # Pos Args check
    if len(sys.argv) != 2:
        print('Incorrect usage! Pass the csv filepath.')
        print('Usage example:')
        print(f'    python {sys.argv[0]} ./data/gps_data.csv')
        sys.exit(1)

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

    # Create plot
    fig, ax1 = plt.subplots()
    
    ax1.set_title(fpath)

    color = 'tab:orange'
    ax1.set_xlabel(df.keys()[0])
    ax1.set_ylabel(df.keys()[1], color=color)
    ax1.plot(t, lat, color=color)
    ax1.tick_params(axis='y', labelcolor=color)

    ax2 = ax1.twinx()

    color = 'tab:blue'
    ax2.set_ylabel(df.keys()[2], color=color)
    ax2.plot(t, lon, color=color)
    ax2.tick_params(axis='y', labelcolor=color)
    
    fig.tight_layout()

    plt.show()
    
    sys.exit(0)


if __name__ == '__main__':
    main()