##!/usr/bin/env python

from json import dumps, loads
from shlex import quote
from configparser import ConfigParser

def minify_json(file_name):
    return dumps(loads(open(file_name, "r", 1).read()), separators=(',', ":"))

def get_i2c_device_list_json_file_name():
    config = ConfigParser()
    config.read('platformio.ini')

    return config['common']['i2c_device_list_json_file_name']

def get_i2c_device_list_json(file_name):
    return minify_json(file_name)

print("'-DARDUIS_I2C_DEVICE_LIST_JSON=\"%s\"'\n" % get_i2c_device_list_json(get_i2c_device_list_json_file_name()))
