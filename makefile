CC = gcc
CFLAGS=-D TEST
EXPORT_BAK = export SIMPLE_BACKUP_SUFFIX=".bak"
FILES = find -regex "\.*/.*\.\(c\|h\)$\"
BKP_FILES = find -regex "\.*/.*\.\(bak\)$\"
FORMAT = indent


format:
	${EXPORT_BAK} && ${FILES} -exec ${FORMAT} {} +

cleanbkp: 
	${BKP_FILES} -exec rm -rf {} + 

