# defined variable $(OBJS) as list of object files
OBJS = uimain.o tokenizer.o history.o

# "default rule" specifying how to build an "object" file (.o) from a C source file (.c)
# this rule includes $(CFLAGS) as one of the cc's parameters
CFLAGS=-g -O3

# first target is built by default. Usually named "all"
all: runTokenizer

# runTokenizer (target) depends on all object files (prerequisites)
runTokenizer: $(OBJS)
	cc -o runTokenizer $(CFLAGS) $(OBJS)

# all object files built from c files that include draw.h
$(OBJS): tokenizer.h history.h

# dletes files generated by compilation
clean:
	rm -f *.o runTokenizer

run:runTokenizer
	./runTokenizer
