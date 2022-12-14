# Build Options
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
# Enable Bootmagic Lite
BOOTMAGIC_ENABLE = yes     
# Turn on mouse:
MOUSEKEY_ENABLE = yes
# Turn on tap dance:
TAP_DANCE_ENABLE = yes
# Dynamic Tapping Term:
DYNAMIC_TAPPING_TERM_ENABLE = yes
# Replicates the normal keyswitch layer handling functionality, but with encoders:
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
# Thumpers
HAPTIC_ENABLE = yes
HAPTIC_DRIVER += SOLENOID
# Audio control and System control
EXTRAKEY_ENABLE = yes
# Enable N-Key Rollover   
NKRO_ENABLE = yes          
# Yay via!
VIA_ENABLE = yes
# link time optimization - slower compile but smaller file size.
LTO_ENABLE = no
