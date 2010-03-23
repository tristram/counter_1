#include "ruby.h"

typedef struct {
    int count;
} Counter;

// C functions

static int next( Counter* cp ) {
    return ++cp->count;
}

static void reset( Counter* cp ) {
    cp->count = 0;
}    

// Memory handling

static void free_structure( Counter* cp ) {
    free( cp );
}

static VALUE allocate_structure( VALUE class_name ) {
    Counter* cp = calloc( 1, sizeof(Counter) );    // guaranteed zeroed memory
    return Data_Wrap_Struct(
            class_name,         // class owning this memory
            0,                  // no mark routine required
            free_structure,     // function called when garbage collected
            cp
    );
}

// Method wrapping

static Counter* retrieve_structure( VALUE self ) {
    Counter* cp;
    Data_Get_Struct( self, Counter, cp );
    return cp;
}

static VALUE wrap_next( VALUE self ) {
    Counter* cp = retrieve_structure( self );
    return INT2FIX( next(cp) );
}

static VALUE wrap_reset( VALUE self ) {
    Counter* cp = retrieve_structure( self );
    reset( cp );
    return Qnil;
}    

// Define methods

static VALUE counter;

void Init_counter() {
    counter = rb_define_class( "Counter", rb_cObject );
    rb_define_alloc_func( counter, allocate_structure );
    rb_define_method( counter, "next", wrap_next, 0 );
    rb_define_method( counter, "reset", wrap_reset, 0 );
}
