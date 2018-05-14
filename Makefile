PGFILEDESC = "pglogical_dump - pg_dump 9.4 with --snapshot support"
PGAPPICON = win32

PROGRAM = pglogical_dump
OBJS	= pg_dump.o common.o pg_dump_sort.o \
	pg_backup_archiver.o pg_backup_db.o pg_backup_custom.o \
	pg_backup_null.o pg_backup_tar.o pg_backup_directory.o \
	pg_backup_utils.o parallel.o compress_io.o dumputils.o \
	keywords.o kwlookup.o tar.o $(WIN32RES)

PG_CPPFLAGS = -I$(libpq_srcdir)
PG_LIBS = -L$(pkglibdir) $(libpq_pgport)

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
