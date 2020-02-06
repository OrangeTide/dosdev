#
################################################################################
all ::
clean ::
.PHONY : all clean
################################################################################
include settings.mk
################################################################################
HOSTCC ?= $(CC)
HOSTLD ?= $(LD)
HOSTAS ?= $(AS)
################################################################################

# reset our variables between runs
define wipe
$(eval
SRCS :=
OBJS :=
EXEC :=
LIBS :=
USES :=
CFLAGS :=
CPPFLAGS :=
CXXFLAGS :=
LDFLAGS :=
LDLIBS :=
TYPE :=
TAG :=
CUR :=
)
endef

# create rules if extension is set
ifneq ($(EXT),)
%$(EXT) : %.o
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

%$(EXT) : %.c
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@
endif

# use an extra expansion to create a clean rule
clean = $(eval clean :: ; $$(RM) $1)

# build an executable or library
define build
$(eval
# find the directory
CUR := $$(dir $1)
TAG := $$(patsubst %/,%,$$(CUR))
$(info Using config: $1)
include $1
OBJS += $$(SRCS:.c=.o)
OBJS := $$(addprefix $$(CUR),$$(OBJS))
EXEC := $$(addprefix $$(CUR),$$(EXEC))
SRCS := $$(addprefix $$(CUR),$$(SRCS))
ifneq ($$(filter lib%,$$(TYPE)),)
# are we building a library?
EXEC := $(addsuffix .a,$$(EXEC))
$$(EXEC) :: $$(EXEC)($$(OBJS))
# TODO: expose library's depedencnies, CFLAGS, LDLIBS, etc to rest of build system
# Reference library as: $(EXEC.$(TAG))
EXEC.$$(TAG) := $$(EXEC)
else
# we must be building a regular executable
EXEC := $(addsuffix $(EXT),$$(EXEC))
$$(EXEC) :: $$(OBJS) $$(foreach u,$$(USES),$$(EXEC.$$u))
endif
all :: $$(EXEC)
# apply all the flags to this project
ifneq ($$(CFLAGS),)
$$(EXEC) :: CFLAGS := $$(CFLAGS)
endif
ifneq ($$(CPPFLAGS),)
$$(EXEC) :: CPPFLAGS := $$(CPPFLAGS)
endif
ifneq ($$(CXXFLAGS),)
$$(EXEC) :: CXXFLAGS := $$(CXXFLAGS)
endif
ifneq ($$(LDFLAGS),)
$$(EXEC) :: LDFLAGS := $$(LDFLAGS)
endif
ifneq ($$(LDLIBS),)
$$(EXEC) :: LDLIBS := $$(LDLIBS)
endif
)
$(call clean,$(EXEC) $(OBJS))
$(call wipe)
endef
################################################################################
SUBDIRS := $(wildcard */project.cfg)

$(call wipe) # make sure nothing stale slips in...
$(foreach d,$(SUBDIRS),$(call build,$d))
