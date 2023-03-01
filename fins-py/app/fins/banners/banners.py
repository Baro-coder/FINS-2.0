import random

BANNER_LONG = '''
  ______  _       ____   _____               _____  _   _   _____ 
 |  ____|| |     / __ \ |  __ \     /\      |_   _|| \ | | / ____|
 | |__   | |    | |  | || |__) |   /  \       | |  |  \| || (___  
 |  __|  | |    | |  | ||  _  /   / /\ \      | |  | . ` | \___ \ 
 | |     | |____| |__| || | \ \  / ____ \    _| |_ | |\  | ____) |
 |_|     |______|\____/ |_|  \_\/_/    \_\  |_____||_| \_||_____/ 
'''

BANNER_LONG_DOT = '''
  ______  _       ____   _____                       _____     _   _      _____   
 |  ____|| |     / __ \ |  __ \     /\              |_   _|   | \ | |    / ____|  
 | |__   | |    | |  | || |__) |   /  \     ______    | |     |  \| |   | (___    
 |  __|  | |    | |  | ||  _  /   / /\ \   |______|   | |     | . ` |    \___ \   
 | |     | |____| |__| || | \ \  / ____ \            _| |_  _ | |\  | _  ____) |_ 
 |_|     |______|\____/ |_|  \_\/_/    \_\          |_____|(_)|_| \_|(_)|_____/(_)
'''

BANNER_SHORT = '''
  ______  _____  _   _   _____ 
 |  ____||_   _|| \ | | / ____|
 | |__     | |  |  \| || (___  
 |  __|    | |  | . ` | \___ \ 
 | |      _| |_ | |\  | ____) |
 |_|     |_____||_| \_||_____/ 
'''

BANNER_SHORT_DOT = '''
  ______  _____     _   _      _____   
 |  ____||_   _|   | \ | |    / ____|  
 | |__     | |     |  \| |   | (___    
 |  __|    | |     | . ` |    \___ \   
 | | _    _| |_  _ | |\  | _  ____) |_ 
 |_|(_)  |_____|(_)|_| \_|(_)|_____/(_)
'''


def get_random_banner() -> str:
    banners = [BANNER_SHORT, 
               BANNER_SHORT_DOT, 
               BANNER_LONG, 
               BANNER_LONG_DOT]
    
    ind = random.randint(0, len(banners)-1)
    return banners[ind]