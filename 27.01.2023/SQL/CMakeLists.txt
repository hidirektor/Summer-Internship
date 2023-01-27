cmake_minimum_required(VERSION 3.24)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c mysql.h field_types.h my_list.h mysql_com.h mysql_version.h mysql_time.h errmsg.h client_plugin.h plugin_auth_common.h my_command.h my_compress.h udf_registration_types.h)
