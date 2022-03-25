#  https://pypi.org/project/pyowm/

import pyowm
from pyowm import OWM
from pyowm.utils import config
from pyowm.utils import timestamps

owm = OWM('9f535261d976d6f8fe34db92a6e49186')
mgr = owm.weather_manager()

place = input('What town/country? ')
observation = mgr.weather_at_place('place')
w = observation.weather

print("It's " + w.detailed_status + " now in " + place)

temp = w.temperature('celsius')["temp"]
print("Temperature" + str(temp))

if temp < 10:
    print("It's cold now you should dress better")
elif temp < 20:
    print("It's not so cold so you can dress not so warmly")