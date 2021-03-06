#include "../thirdparty/catch2/catch.hpp"

#include "tests.hpp"
#include "../testing.hpp"
#include "../character.hpp"
#include "../i18n.hpp"
#include "../item.hpp"
#include "../itemgen.hpp"
#include "../ui.hpp"
#include "../variables.hpp"
#include <sstream>

using namespace std::literals::string_literals;
using namespace elona;

TEST_CASE("test i18n builtin: he()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    character& out_of_fov = testing::create_chara(PUTIT_PROTO_ID, 0, 0);
    update_slight();
    you.sex = 0;
    chara.sex = 1;

    SECTION("Japanese")
    {
        testing::set_japanese();
        REQUIRE(i18n::fmt_hil("${he2(_1)}", you) == u8"彼");
        REQUIRE(i18n::fmt_hil("${he2(_1)}", chara) == u8"彼女");
    }
    SECTION("English")
    {
        testing::set_english();
        REQUIRE(i18n::fmt_hil("${he2(_1)}", you) == u8"he");
        REQUIRE(i18n::fmt_hil("${he2(_1)}", chara) == u8"she");
        REQUIRE(i18n::fmt_hil("${he(_1)}", you) == u8"you");
        REQUIRE(i18n::fmt_hil("${he(_1)}", chara) == u8"she");
        REQUIRE(i18n::fmt_hil("${he(_1)}", out_of_fov) == u8"it");
    }
}

TEST_CASE("test i18n builtin: his()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    character& out_of_fov = testing::create_chara(PUTIT_PROTO_ID, 0, 0);
    update_slight();
    you.sex = 0;
    chara.sex = 1;

    SECTION("Japanese")
    {
        testing::set_japanese();
        REQUIRE(i18n::fmt_hil("${his2(_1)}", you) == u8"あなたの");
        REQUIRE(i18n::fmt_hil("${his2(_1)}", chara) == u8"彼女の");
    }
    SECTION("English")
    {
        testing::set_english();
        REQUIRE(i18n::fmt_hil("${his2(_1)}", you) == u8"your");
        REQUIRE(i18n::fmt_hil("${his2(_1)}", chara) == u8"her");
        REQUIRE(i18n::fmt_hil("${his(_1)}", you) == u8"your");
        REQUIRE(i18n::fmt_hil("${his(_1)}", chara) == u8"her");
        REQUIRE(i18n::fmt_hil("${his(_1)}", out_of_fov) == u8"its");
    }
}

TEST_CASE("test i18n builtin: him()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    character& out_of_fov = testing::create_chara(PUTIT_PROTO_ID, 0, 0);
    update_slight();
    you.sex = 0;
    chara.sex = 1;

    SECTION("Japanese")
    {
        testing::set_japanese();
        REQUIRE(i18n::fmt_hil("${him2(_1)}", you) == u8"彼");
        REQUIRE(i18n::fmt_hil("${him2(_1)}", chara) == u8"彼女");
    }
    SECTION("English")
    {
        testing::set_english();
        REQUIRE(i18n::fmt_hil("${him2(_1)}", you) == u8"him");
        REQUIRE(i18n::fmt_hil("${him2(_1)}", chara) == u8"her");
        REQUIRE(i18n::fmt_hil("${him(_1)}", you) == u8"yourself");
        REQUIRE(i18n::fmt_hil("${him(_1)}", chara) == u8"her");
        REQUIRE(i18n::fmt_hil("${him(_1)}", out_of_fov) == u8"it");
    }
}

TEST_CASE("test i18n builtin: name()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    character& out_of_fov = testing::create_chara(PUTIT_PROTO_ID, 0, 0);
    update_slight();

    REQUIRE(i18n::fmt_hil("${name(_1)}", you) == u8"you");
    REQUIRE(i18n::fmt_hil("${name(_1)}", chara) == u8"the putit");
    REQUIRE(i18n::fmt_hil("${name(_1)}", out_of_fov) == u8"something");
}

TEST_CASE("test i18n builtin: basename()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    elona::cdatan(0, you.index) = u8"Orville";
    update_slight();

    REQUIRE(i18n::fmt_hil("${basename(_1)}", you) == u8"Orville");
    REQUIRE(i18n::fmt_hil("${basename(_1)}", chara) == u8"putit");
}

TEST_CASE("test i18n builtin: s()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    update_slight();

    REQUIRE(i18n::fmt_hil("something go${s(_1)} to hell.", chara) == u8"something gos to hell.");
    REQUIRE(i18n::fmt_hil("something go${s(_1, true)} to hell.", chara) == u8"something goes to hell.");
}

TEST_CASE("test i18n builtin: is()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    update_slight();

    REQUIRE(i18n::fmt_hil("you ${is(_1)} killed.", you) == u8"you are killed.");
    REQUIRE(i18n::fmt_hil("something ${is(_1)} killed.", chara) == u8"something is killed.");
    REQUIRE(i18n::fmt_hil("you ${is(true)} killed.", you) == u8"you are killed.");
    REQUIRE(i18n::fmt_hil("something ${is(false)} killed.", chara) == u8"something is killed.");
}

TEST_CASE("test i18n builtin: have()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    update_slight();

    REQUIRE(i18n::fmt_hil("${have(_1)}", you) == u8"have");
    REQUIRE(i18n::fmt_hil("${have(_1)}", chara) == u8"has");
}

TEST_CASE("test i18n builtin: himself()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    update_slight();
    you.sex = 0;
    chara.sex = 1;

    REQUIRE(i18n::fmt_hil("${himself(_1)}", you) == u8"yourself");
    REQUIRE(i18n::fmt_hil("${himself(_1)}", chara) == u8"herself");
}

TEST_CASE("test i18n builtin: his_owned()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    update_slight();

    REQUIRE(i18n::fmt_hil("you${his_owned(_1)}", you) == u8"your");
    REQUIRE(i18n::fmt_hil("the putit${his_owned(_1)}", chara) == u8"the putit's");
}

TEST_CASE("test i18n builtin: name_nojob()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_english();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    elona::cdatan(0, chara.index) = "Putit the mochi vendor";
    update_slight();

    REQUIRE(i18n::fmt_hil("${name_nojob(_1)}", chara) == u8"Putit ");
}

TEST_CASE("test i18n builtin: kare_wa()", "[I18N: Builtins]")
{
    testing::start_in_debug_map();
    testing::set_japanese();
    character& you = elona::cdata[0];
    character& chara = testing::create_chara(PUTIT_PROTO_ID, 23, 23);
    character& out_of_fov = testing::create_chara(PUTIT_PROTO_ID, 0, 0);
    update_slight();

    REQUIRE(i18n::fmt_hil("${kare_wa(_1)}", you) == u8"");
    REQUIRE(i18n::fmt_hil("${kare_wa(_1)}", chara) == u8"putitは");
    REQUIRE(i18n::fmt_hil("${kare_wa(_1)}", out_of_fov) == u8"それは");
}
