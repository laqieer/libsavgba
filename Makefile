#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM)
endif
ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>devkitPro)
endif
include $(DEVKITARM)/gba_rules

BUILD		:=	build
SOURCES		:=	src
INCLUDES	:=	include

ARCH	:=	-mthumb -mthumb-interwork

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
CFLAGS	:=	-g -O3 -Wall -Wno-switch -Wno-multichar -Wno-stringop-overflow $(ARCH) $(INCLUDE)
ASFLAGS	:=	-g -Wa,--warn $(ARCH)

#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))

export TARGET	:=	$(CURDIR)/lib/$(notdir $(CURDIR)).a

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir))

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

export OFILES_SRC	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)

export OFILES	:=	$(OFILES_SRC)

LIBTONC 	:= $(LIBGBA)/../libtonc

export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) -I$(LIBGBA)/include -I$(LIBTONC)/include
export DEPSDIR	:=	$(CURDIR)/build

TESTS := $(wildcard test/*)

.PHONY: $(BUILD) test smoke docs version pack release clean $(TESTS)

$(BUILD):
	@[ -d lib ] || mkdir -p lib
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

test: $(TESTS)
$(TESTS):
	$(MAKE) -C $@

smoke:
	@for dir in $(TESTS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done

docs:
	@doxygen

version:
	@standard-version

pack:
	@zip -r $(notdir $(CURDIR))-`cat VERSION`.zip include lib LICENSE CHANGELOG.md README.md

release:
	@git push --follow-tags origin main
	@gh release create v`cat VERSION` $(notdir $(CURDIR))-`cat VERSION`.zip -F CHANGELOG.md

clean:
	@rm -fr $(BUILD) lib *.zip
	@for dir in $(TESTS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done


#---------------------------------------------------------------------------------
else

DEPENDS	:=	$(OFILES:.o=.d)

#---------------------------------------------------------------------------------
$(TARGET): $(OFILES)

#---------------------------------------------------------------------------------
%.a: $(OFILES)
	@echo $@
	@rm -f $@
	@$(AR) rcs $@ $(OFILES)

-include $(DEPENDS)

endif
#---------------------------------------------------------------------------------
