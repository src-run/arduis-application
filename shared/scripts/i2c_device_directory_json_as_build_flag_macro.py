##!/usr/bin/env python

from json         import dumps  as json_dumps
from json         import loads  as json_loads
from os           import access as path_access
from os           import R_OK   as PATH_READABLE
from os           import path
from os           import stat
from configparser import ConfigParser

#
# script runtime config dictionary
#
scriptConfigDict = {
    'project_config__pini_file_path': 'platformio.ini',
    'project_config__json_file_path__i2c_device_directory__sect_key': 'common',
    'project_config__json_file_path__i2c_device_directory__optn_key': 'i2c_device_directory_json_file_path',
}

#
# generic file exception class definition
#
class GenericFileException(Exception):
    """Exception raised for generic file errors.

    Attributes:
        message   -- explanation of the error
        file_path -- file path related to the error
        file_data -- file data related to the error
    """

    def __init__(self, message='Encountered a generic, unspecified file error', file_path=None, file_data=None):
        self.file_path = file_path
        self.file_data = file_data

        super().__init__(self.__append_file_path_to_message(
            self.__append_file_info_to_message(message, file_path, file_data), file_path)
        )

    def __append_file_path_to_message(self, message, file_path=None):
        if file_path is not None:
            message += ': "{path:s}"'.format(path=file_path)

        return message

    def __append_file_info_to_message(self, message, file_path=None, file_data=None):
        file_info = []
        file_size = len(file_data.encode('utf-8')) if file_data is not None else -1

        try:
            file_stat = stat(file_path)
            file_size = file_stat.st_size
            file_info.append('uid="{uid:d}"'.format(uid=file_stat.st_uid))
            file_info.append('gid="{gid:d}"'.format(gid=file_stat.st_gid))
        except Exception:
            pass

        if file_size >= 0:
            file_info.append('bytes="{bytes:d}"'.format(bytes=file_size))

        if file_data is not None:
            file_info.append('lines="{lines:d}"'.format(lines=file_data.count('\n')))

        return self._append_dictionary_items_to_message(message, 'file', file_info)

    def _append_dictionary_items_to_message(self, message, context, dictionary):
        if len(dictionary) > 0:
            message += ' ({context:s} {joined:s})'.format(context=context, joined=', '.join(dictionary))

        return message

#
# project configuration file exception class definition
#
class ProjectConfFileException(GenericFileException):
    """Exception raised for project config file errors.

    Attributes:
        message   -- explanation of the error
        file_path -- ini config file path related to the error
        conf_sect -- ini config section name related to error
        conf_optn -- ini config option name related to error
        file_data -- ini config file data related to the error
    """

    def __init__(self, message='Encountered a generic, unspecified read project config error', file_path=None, conf_sect=None, conf_optn=None, file_data=None):
        self.conf_sect = conf_sect
        self.conf_optn = conf_optn

        super().__init__(self.__append_conf_info_to_message(message, conf_sect, conf_optn), file_path, file_data)

    def __append_conf_info_to_message(self, message, conf_sect=None, conf_optn=None):
        conf_info = []

        if conf_sect is not None:
            conf_info.append('section key="{sect:s}"'.format(sect=conf_sect))

        if conf_optn is not None:
            conf_info.append('option name="{optn:s}"'.format(optn=conf_optn))

        return self._append_dictionary_items_to_message(message, 'config', conf_info)

#
# file sanitization and expantion exception class definition
#
class SanitizeAndExpandFilePathException(GenericFileException):
    pass

#
# read file exception class definition
#
class ReadFileException(GenericFileException):
    pass

#
# parse json file exception class definition
#
class ParseJsonFileException(GenericFileException):
    pass

#
# main function definition
#
def main():

    #
    # sanitize and expand file path function definition
    #
    def sanitize_and_expand_file_path(file_path):
        if not path.exists(file_path):
            raise SanitizeAndExpandFilePathException('File path does not exist', file_path)

        if not path_access(file_path, PATH_READABLE):
            raise SanitizeAndExpandFilePathException('File path is not readable (inadequate permissions)', file_path)

        try:
            return path.abspath(path.expanduser(path.expandvars(file_path)))
        except Exception as e:
            raise SanitizeAndExpandFilePathException('File path could not be expanded', file_path) from e

    #
    # minify json read from file path
    #
    def read_and_minify_json_from_file_path(file_path):
        file_path = sanitize_and_expand_file_path(file_path)

        try:
            json_data = open(file_path, 'r', 1).read()
        except Exception as e:
            raise ReadFileException('File could not be opened for reading', file_path) from e

        try:
            return json_dumps(json_loads(json_data), skipkeys=True, check_circular=False, indent=None, separators=(',', ':'), sort_keys=True)
        except Exception as e:
            raise ParseJsonFileException('File json could not be loaded/parsed', file_path, json_data) from e

    #
    # get i2c devices json file path from platformio ini config
    #
    def get_i2c_device_directory_json_file_path_from_project_config():
        proj_file_path = sanitize_and_expand_file_path(scriptConfigDict['project_config__pini_file_path'])
        proj_conf_sect = scriptConfigDict['project_config__json_file_path__i2c_device_directory__sect_key']
        proj_conf_optn = scriptConfigDict['project_config__json_file_path__i2c_device_directory__optn_key']

        proj_conf_data = ConfigParser()
        proj_conf_code = proj_conf_data.read(proj_file_path)

        if not len(proj_conf_code) > 0:
            raise ProjectConfFileException('Project config file could not be parsed', proj_file_path)

        if not proj_conf_data.has_section(proj_conf_sect):
            raise ProjectConfFileException('Project config file does not contain requested ini section key', proj_file_path, proj_conf_sect)

        if not proj_conf_data.has_option(proj_conf_sect, proj_conf_optn):
            raise ProjectConfFileException('Project config file does not contain requested ini option name', proj_file_path, proj_conf_sect, proj_conf_optn)

        return proj_conf_data[proj_conf_sect][proj_conf_optn]

    print("'-DARDUIS_I2C_DEVICE_LIST_JSON=\"%s\"'\n" % read_and_minify_json_from_file_path(
        get_i2c_device_directory_json_file_path_from_project_config()
    ))

#
# execute the main function if called as script and not if imported as module
#
if __name__== "__main__":
    main()
