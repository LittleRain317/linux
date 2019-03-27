#ifndef _24k_vector_t
#error: No define "_24k_vector_t"
#endif

#ifndef _STDLIB_H // malloc(), exit()
#include <stdlib.h>
#ifndef _STDLIB_H
#define _STDLIB_H
#endif
#endif

#ifndef _STRING_H // memcpy()
#include <string.h>
#ifndef _STRING_H
#define _STRING_H
#endif
#endif

#ifndef _STDARG_H // va_list
#include <stdarg.h>
#ifndef _STDARG_H
#define _STDARG_H
#endif
#endif

#define _24k_vector_lk__(T)	T##_##vector
#define _24k_vector_lk(T)	_24k_vector_lk__(T)
#define _24k_vector	_24k_vector_lk(_24k_vector_t)

#define _24k__(x, T)	T##_##vector##_##x
#define _24k_(x, T)	_24k__(x, T)
#define _24k(x)		_24k_(x, _24k_vector_t)

#define _24k_error__(fmt, ...)	_24k(fatal_error)(fmt, __VA_ARGS__)
#define _24k_error(fmt, ...)	_24k_error__(fmt, __VA_ARGS__)

#define _24k_strmac__(x)	#x
#define _24k_strmac(x)		_24k_strmac__(x)

#define _24k_vector_init_size	0x4
#define _24k_expand_times	2.0

void
_24k(fatal_error) (const char *fmt, ...) {
#ifndef _24k_vector_not_print_error
	va_list ap;
	va_start(ap, fmt);
	fprintf(stderr, "_24k: error: ");
	vfprintf(stderr, fmt, ap);
	va_end(ap);
#endif
#ifndef _24k_vector_not_exit
	exit(24);
#endif
}

typedef struct{
	_24k_vector_t *data;
	size_t size;
	size_t capacity;
}_24k_vector;

int
_24k(init) (_24k_vector *vec) {
	vec->data = (_24k_vector_t*) malloc (_24k_vector_init_size * sizeof(_24k_vector_t));
	if ( ! vec->data ) {
		_24k_error("%s: Memory allocation failed\n", _24k_strmac(_24k(init)));
		return 0;
	}
	vec->size = 0;
	vec->capacity = _24k_vector_init_size;
	return 1;
}

void
_24k(destroy) (_24k_vector *vec) {
	free(vec->data);
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = 0;
}

_24k_vector_t*
_24k(at) (_24k_vector *vec, size_t pos) {
	if ( pos<0 || pos>=vec->size ) {
		_24k_error("%s: Index out of bound, pos=%d, size=%d\n", _24k_strmac(_24k(at)), pos, vec->size);
		return 0;
	}
	return vec->data + pos;
}

_24k_vector_t*
_24k(begin) (_24k_vector *vec) {
	if ( ! vec->size ) {
		_24k_error("%s: vector is empty\n", _24k_strmac(_24k(front)));
		return 0;
	}
	return vec->data;
}

_24k_vector_t*
_24k(end) (_24k_vector *vec) {
	if ( ! vec->size ) {
		_24k_error("%s: vector is empty\n", _24k_strmac(_24k(back)));
		return 0;
	}
	return vec->data + vec->size - 1;
}

_24k_vector_t*
_24k(data) (_24k_vector *vec) {
	return vec->data;
}

int
_24k(empty) (_24k_vector *vec) {
	if ( vec->size )
		return 0;
	return 1;
}

size_t
_24k(size) (_24k_vector *vec) {
	return vec->size;
}

int
_24k(reserve) (_24k_vector *vec, size_t new_cap) {
	_24k_vector_t *p;
	if (new_cap > vec->capacity) {
		p = (_24k_vector_t*) realloc (vec->data, new_cap * sizeof(_24k_vector_t));
		if ( ! p ) {
			_24k_error("%s: Memory reallocation failed\n", _24k_strmac(_24k(reserve)));
			return 0;
		}
		vec->data = p;
		vec->capacity = new_cap;
	}
	return 1;
}

size_t
_24k(capacity) (_24k_vector *vec) {
	return vec->capacity;
}

void
_24k(shrink_to_fit) (_24k_vector *vec) {
	if (vec->size < vec->capacity) {
		vec->data = realloc(vec->data, (vec->size ? vec->size : 1) * sizeof(_24k_vector_t));
		vec->capacity = vec->size ? vec->size : 1;
	}
}

void
_24k(clear) (_24k_vector *vec) {
	vec->size = 0;
}

int
_24k(resize) (_24k_vector *vec, size_t count) {
	int r;
	if (vec->size >= count)
		vec->size = count;
	else {
		r = _24k(reserve)(vec, count);
		if (r)
			memset(vec + vec->size, 0, (count-vec->size) * sizeof(_24k_vector_t));
		else
			return 0;
	}
	return 1;
}

int
_24k(insert) (_24k_vector *vec, size_t pos, _24k_vector_t *t) {
	_24k_vector_t *p0, *p1;

	if ( pos<0 || pos>vec->size ) {
		_24k_error("%s: Index out of bound, pos=%d, size=%d\n", _24k_strmac(_24k(insert)), pos, vec->size);
		return 0;
	}
	if (vec->size == vec->capacity && ! _24k(reserve)(vec, (size_t)(vec->capacity * _24k_expand_times)))
		return 0;
	p0 = vec->data + vec->size;
	p1 = vec->data + pos;
	while ( p0 > p1 )
		memcpy(p0, p0-1, sizeof(_24k_vector_t)), --p0;
	memcpy(p1, t, sizeof(_24k_vector_t));
	++vec->size;
	return 1;
}

int
_24k(erase) (_24k_vector *vec, size_t pos) {
	_24k_vector_t *p0, *p1;

	if (pos<0 || pos>=vec->size) {
		_24k_error("%s: Index out of bound, pos=%d, size=%d\n", _24k_strmac(_24k(erase)), pos, vec->size);
		return 0;
	}
	p0 = vec->data + pos;
	p1 = vec->data + vec->size - 1;
	do
		memcpy(p0, p0+1, sizeof(_24k_vector_t));
	while (++p0 < p1);
	--vec->size;
	return 1;
}

int
_24k(push_back) (_24k_vector *vec, _24k_vector_t *t) {
	return _24k(insert)(vec, vec->size, t);
}

int
_24k(pop_back) (_24k_vector *vec) {
	return _24k(erase)(vec, vec->size-1);
}

int
_24k(traverse) (_24k_vector *vec, int (*visit)(_24k_vector_t*)) {
	int r;
	size_t i, size = vec->size;
	_24k_vector_t *p = vec->data;

	for (i=0; i<size; ++i,++p) {
		r = visit(p);
		if (r)
			return r;
	}
	return 0;
}

int
_24k(assign) (_24k_vector *vec, size_t count, _24k_vector_t *t) {
	size_t i;

	_24k(clear)(vec);
	for (i=0; i<count; ++i)
		if ( ! _24k(push_back)(vec, t))
			return 0;
	return 1;
}

#undef _24k_vector_lk__
#undef _24k_vector_lk
#undef _24k_vector

#undef _24k__
#undef _24k_
#undef _24k

#undef _24k_error__
#undef _24k_error

#undef _24k_strmac__
#undef _24k_strmac

#undef _24k_vector_init_size
#undef _24k_expand_times

#undef _24k_vector_t
