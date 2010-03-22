#!/usr/bin/ruby

require "minitest/unit"
require "minitest/autorun"

class CounterTest < MiniTest::Unit::TestCase
    def test_can_create_c_object
        require "lib/counter"
        counter = Counter.new
    end
end
