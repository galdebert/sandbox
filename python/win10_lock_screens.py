#!/usr/bin/env python3

import os
import shutil
import glob
import itertools

# put your user here vvvvvvvvv
src_dir = r'C:\Users\guillaume\AppData\Local\Packages\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\LocalState\Assets'

this_dir = os.path.dirname(__file__)
dest_dir = os.path.join(this_dir, 'output')
shutil.rmtree(dest_dir, ignore_errors=True)
os.makedirs(dest_dir)

for p, i in zip(glob.glob(src_dir + '/*'), itertools.count()):
    shutil.copyfile(p, "{}/{}.png".format(dest_dir, i))
