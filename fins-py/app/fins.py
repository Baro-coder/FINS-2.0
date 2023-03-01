import sys

import fins.banners.banners as banner

def _show_banner():
    obj = banner.get_random_banner()
    print(obj)
    print('\n')

def main():
    _show_banner()

    while True:
        cmd = input('FINS-App$> ')
        
        if cmd == 'exit':
            break;

    sys.exit(0)



if __name__ == '__main__':
    main()