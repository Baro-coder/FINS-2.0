import sys
import pandas as pd
import matplotlib.pyplot as plt


def main() -> None:
    if len(sys.argv) != 3:
        print('Incorrect usage! Pass the csv filepath.')
        print('Usage example:')
        print(f'    python {sys.argv[0]} ./data/data1.csv ./data/data2.csv')
        sys.exit(1)

    

if __name__ == '__main__':
    main()