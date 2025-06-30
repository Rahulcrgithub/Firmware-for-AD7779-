SRCS += $(PROJECT)/main.c

INCS += $(INCLUDE)/no_os_delay.h     \
                $(INCLUDE)/no_os_error.h     \
                $(INCLUDE)/no_os_spi.h       \
                $(INCLUDE)/no_os_util.h \
                $(INCLUDE)/no_os_units.h \
                $(INCLUDE)/no_os_gpio.h \
                $(INCLUDE)/no_os_delay.h \
                $(INCLUDE)/no_os_alloc.h \
		$(INCLUDE)/no_os_mutex.h \
                $(DRIVERS)/adc/ad7779/ad7779.h \
		$(DRIVERS)/platform/linux/linux_spi.h

SRCS +=  $(DRIVERS)/api/no_os_spi.c  \
                $(NO-OS)/util/no_os_util.c \
                $(NO-OS)/util/no_os_alloc.c \
                $(NO-OS)/util/no_os_mutex.c \
                $(DRIVERS)/api/no_os_gpio.c \
		$(DRIVERS)/adc/ad7779/ad7779.c \
                $(DRIVERS)/platform/linux/linux_spi.c \
                $(DRIVERS)/platform/linux/linux_delay.c
