import sys
import pandas as pd
import matplotlib.pyplot as plt


def main() -> None:
    # Pos Args check
    if len(sys.argv) < 2:
        print('Incorrect usage! Pass the csv filepath.')
        print('Usage example:')
        print(f'    python {sys.argv[0]} ./data/data1.csv ./data/data2.csv ./data/dataN.csv')
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

        except TypeError as e:
            print('Invalid data!')

    
    # Show plots
    plt.show()
    
    sys.exit(0)


if __name__ == '__main__':
    main()