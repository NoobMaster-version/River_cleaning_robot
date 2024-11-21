set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "mcpwm_interface.c"  "motor_driver.c"  "river.c"  "utils.c" "joy_stick.c" "nvs.c" "servo.c")
set(COMPONENT_ADD_INCLUDEDIRS "include")

register_component()
