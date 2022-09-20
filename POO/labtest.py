from skimage import io
from skimage import color
from skimage import data
from pylab import *
import matplotlib.pyplot as plt
from skimage.io import imread_collection
from sys import getsizeof



seq = imread_collection("C:\\Users\\vladi\\OneDrive\\Desktop\\UTM\\POO\\Huge Meme Pack\\Meme pack by LiquidIllusion\\*.jpg", conserve_memory=True)

for name,elem in enumerate(seq):
    path = f'C:\\Users\\vladi\\OneDrive\\Desktop\\UTM\\POO\\changed_color_panels\\{name}.jpg'

    img_gray = color.rgb2gray(elem)
    io.imsave(path,img_gray)



