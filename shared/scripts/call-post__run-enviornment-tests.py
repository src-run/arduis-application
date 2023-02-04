##!/usr/bin/env python

from json         import dumps  as json_dumps
from json         import loads  as json_loads
from os           import access as path_access
from os           import R_OK   as PATH_READABLE
from os           import path
from os           import stat
from configparser import ConfigParser

Import("env")
Import("projenv")

#
# script runtime config dictionary
#
scriptConfigDict = {
    'project_config__pini_file_path': 'platformio.ini',
    'project_config__json_file_path__i2c_device_directory__sect_key': 'config_common__globals',
    'project_config__json_file_path__i2c_device_directory__optn_key': 'i2c_device_directory_json_file_path',
}

#
# main function definition
#
def main():

    return

    self_abs_path = path.basename(path.abspath('call-post__run-enviornment-tests.py'))

    print("(POST @ " + self_abs_path + ") -> env.Dump(): [")
    print(env.Dump() + "]\n")
    print("(POST @ " + self_abs_path + ") -> projenv.Dump(): [")
    print(projenv.Dump() + "]\n")


#
# execute the main function
#
main()
