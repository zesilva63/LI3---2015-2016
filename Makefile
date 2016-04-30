CC=gcc

OBJS := $(patsubst src/%.c, obj/%.o,$(wildcard src/*.c))

CFLAGS= -Wno-unused-result -O2 -ansi

gereVendas:$(OBJS)
		$(CC) $(CFLAGS) -o gereVendas $(OBJS) 

debug: CFLAGS := -g
debug: compile

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<

obj/main.o: src/headers/global.h src/headers/produtos.h src/headers/clientes.h src/headers/filial.h src/headers/interpretador.h src/headers/faturacao.h
obj/avl.o: src/headers/avl.h src/headers/global.h
obj/leituras.o: src/headers/leituras.h src/headers/clientes.h src/headers/catalogo.h src/headers/produtos.h src/headers/venda.h src/headers/filial.h src/headers/faturacao.h src/headers/global.h
obj/array_dinamico.o: src/headers/array_dinamico.h src/headers/avl.h src/headers/global.h
obj/catalogo.o: src/headers/catalogo.h src/headers/avl.h src/headers/array_dinamico.h src/headers/global.h
obj/clientes.o: src/headers/clientes.h src/headers/catalogo.h src/headers/global.h
obj/produtos.o: src/headers/produtos.h src/headers/catalogo.h src/headers/global.h
obj/venda.o: src/headers/venda.h src/headers/clientes.h src/headers/produtos.h src/headers/global.h
obj/interpretador.o: src/headers/interpretador.h src/headers/clientes.h src/headers/produtos.h src/headers/faturacao.h src/headers/filial.h src/headers/global.h
obj/heap.o: src/headers/heap.h src/headers/global.h
obj/global.o: src/headers/global.h
obj/faturacao.o: src/headers/faturacao.h src/headers/catalogo.h src/headers/venda.h src/headers/produtos.h src/headers/global.h
obj/filial.o: src/headers/filial.h src/headers/avl.h src/headers/array_dinamico.h src/headers/heap.h src/headers/catalogo.h src/headers/venda.h src/headers/produtos.h src/headers/clientes.h src/headers/global.h
obj/queries.o: src/headers/queries.h src/headers/faturacao.h src/headers/filial.h src/headers/avl.h src/headers/array_dinamico.h src/headers/heap.h src/headers/catalogo.h src/headers/venda.h src/headers/produtos.h src/headers/clientes.h src/headers/global.h

run:$(OBJS)
	$(CC) $(CFLAGS) -o gereVendas $(OBJS)
	./gereVendas

clean:
	-@rm gereVendas
	-@rm -rf obj

cleanAll: clean
	-@rm -rf doc
	-@rm -rf html

.PHONY: doc
doc:$(OBJS)
		doxygen doxygen.conf