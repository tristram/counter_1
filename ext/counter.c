#include "ruby.h"

typedef struct {
} Counter;

static void free_structure( Counter* cp ) {
    free( cp );
}

static VALUE allocate_structure( VALUE class_name ) {
    Counter* cp = calloc( 1, sizeof(Counter) );
    return Data_Wrap_Struct(
            class_name,         // class owning this memory
            0,                  // no mark routine required
            free_structure,     // function called when garbage collected
            cp
    );
}

static VALUE initialize( VALUE self ) {
    return self;
}

static VALUE next( VALUE self ) {
    return INT2FIX( 1 );
}

static VALUE counter;

void Init_counter() {
    counter = rb_define_class( "Counter", rb_cObject );
    rb_define_alloc_func( counter, allocate_structure );
    rb_define_method( counter, "initialize", initialize, 0 );
    rb_define_method( counter, "next", next, 0 );
}
