#include "ruby.h"

static VALUE next( VALUE self ) {
    return INT2FIX( 1 );
}

static VALUE initialize( VALUE self ) {
    return self;
}

static VALUE counter;

void Init_counter() {
    counter = rb_define_class( "Counter", rb_cObject );
    rb_define_method( counter, "initialize", initialize, 0 );
    rb_define_method( counter, "next", next, 0 );
}
