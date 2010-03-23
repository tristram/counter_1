#include "ruby.h"

typedef struct {
    int count;
} Counter;

static void free_structure( Counter* cp ) {
    free( cp );
}

static VALUE allocate_structure( VALUE class_name ) {
    Counter* cp = calloc( 1, sizeof(Counter) );
    cp->count = 1;
    return Data_Wrap_Struct(
            class_name,         // class owning this memory
            0,                  // no mark routine required
            free_structure,     // function called when garbage collected
            cp
    );
}

static VALUE next( VALUE self ) {
    Counter* cp;
    Data_Get_Struct( self, Counter, cp );
    return INT2FIX( cp->count );
}

static VALUE counter;

void Init_counter() {
    counter = rb_define_class( "Counter", rb_cObject );
    rb_define_alloc_func( counter, allocate_structure );
    rb_define_method( counter, "next", next, 0 );
}
