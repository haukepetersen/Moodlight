
# download and unzip locations and names
STM_LIB_URL = http://www.st.com/st-web-ui/static/active/en/st_prod_software_internet/resource/technical/software/firmware/stm32f4_dsp_stdperiph_lib.zip
STM_LIB_ZIPFOLDER = STM32F4*
STM_LIB_TEMP = /tmp/STMF4_tmp/

# collect objects that will be build
LIB_BINDIR = $(STM_LIB_BASE)/bin/
SRC = $(wildcard $(STM_LIB_SRCDIR)*.c)
SRCCLEAN = $(notdir $(SRC))
OBJ = $(SRCCLEAN:%.c=$(LIB_BINDIR)%.o)

# define the module constant (but this should not be needed)
MODULE = $(STM_LIB_NAME)

.PHONY: all clean

all: $(BINDIR)$(STM_LIB_NAME).a $(STM_LIB_BASE)lib

$(BINDIR)$(STM_LIB_NAME).a: $(OBJ)
	@$(AR) -rc $(BINDIR)$(STM_LIB_NAME).a $(OBJ)

# pull in dependency info for *existing* .o files
-include $(OBJ:.o=.d)

$(LIB_BINDIR)%.o: $(STM_LIB_SRCDIR)%.c
	@mkdir -p $(LIB_BINDIR)
	$(info    [CC]   $(STM_LIB_SRCDIR)$*.c)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(STM_LIB_SRCDIR)$*.c -o $(LIB_BINDIR)$*.o
	@$(CC) $(CFLAGS) $(INCLUDES) -MM $(STM_LIB_SRCDIR)$*.c > $(LIB_BINDIR)$*.d
	@printf "$(LIB_BINDIR)"|cat - $(LIB_BINDIR)$*.d > /tmp/riot_out && mv /tmp/riot_out $(LIB_BINDIR)$*.d

# see if the library is already present, otherwise download it
$(STM_LIB_BASE)lib:
	$(shell if [ ! -d $(STM_LIB_BASE)lib ]; then \
	  echo "  [STLIB] the STM standard periphial library for the STM32F4 is missing, will download it now from ST" ; \
	  if [ -d $(STM_LIB_TEMP) ]; then rm -r -f $(STM_LIB_TEMP); fi ; \
	  mkdir $(STM_LIB_TEMP); \
	  wget -O $(STM_LIB_TEMP)stmlib.zip $(STM_LIB_URL) ; \
	  unzip -q -d $(STM_LIB_TEMP) $(STM_LIB_TEMP)stmlib.zip ; \
	  mv $(STM_LIB_TEMP)$(STM_LIB_ZIPFOLDER) $(STM_LIB_BASE)/lib ; \
	  rm -r -f $(STM_LIB_TEMP) ; \
	  echo "  [STLIB] successfully aquired STM lib\n" ; \
	 fi )
	touch -c $@

clean:
	@rm -r -f $(STM_LIB_BASE)/bin
