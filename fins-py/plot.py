import sys
import pandas as pd
import matplotlib.pyplot as plt

'''
    Description:
        Program to draw plots by data from csv files.
        All data are scaled to ``THE SAME`` Y axis scale.
    
    Params:
        <datafilepath> : Path to csv file with data to visualization.
                            It is available to pass multiple paths.
                            
    Example:
        python plot_scale_single.py ./data/data1.csv ./data/data2.csv ./data/org/dataorg1.csv
        
'''

def main() -> None:
    # Pos Args check
    if len(sys.argv) < 2:
        print('Incorrect usage! Pass the csv filepath.')
        print('Usage example:')
        print(f'    python {sys.argv[0]} ./data/data1.csv ./data/data2.csv')
        sys.exit(1)
    
    # Examine every passed csv file
    for i in range(1, len(sys.argv)):
        fpath = sys.argv[i]
        print(f'File: {fpath} : ', end='')
        
        try:
            # Try to open given file and read content
            df = pd.read_csv(fpath)
            
            # Create plot
            df.set_index(df.keys()[0]).plot(title=fpath)
            print('Loaded.')
        
        except FileNotFoundError as e:
            print('Not Found!')
    
    # Show plots
    plt.show()
    
    sys.exit(0)


if __name__ == '__main__':
    main()