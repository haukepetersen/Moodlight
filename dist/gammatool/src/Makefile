
PROJECT = Gammatable

CC = @javac
RUN = @java


.PHONY: all run clean


all: $(PROJECT).class


$(PROJECT).class: $(PROJECT).java
	$(info [CC] $<)
	$(CC) $<

run: $(PROJECT).class
	$(RUN) $(PROJECT)

clean: 
	@rm -r -f *.class
