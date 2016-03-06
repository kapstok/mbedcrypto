#include <catch.hpp>
#include <iostream>

#include "src/mbedtls_config.h"
#include "generator.hpp"
#include "mbedcrypto/hash.hpp"
///////////////////////////////////////////////////////////////////////////////
namespace {
using namespace mbedcrypto;
///////////////////////////////////////////////////////////////////////////////
const char* long_md2() {
    return "4b2ffc802c256a38fd6ccb575cccc27c";
}

const char* long_md4() {
    return "8db2ba4980fa7d57725e42782ab47b42";
}

const char* long_md5() {
    return "db89bb5ceab87f9c0fcc2ab36c189c2c";
}

const char* long_sha1() {
    return "cd36b370758a259b34845084a6cc38473cb95e27";
}

const char* long_sha224() {
    return "b2d9d497bcc3e5be0ca67f08c86087a51322ae48b220ed9241cad7a5";
}

const char* long_sha256() {
    return "2d8c2f6d978ca21712b5f6de36c9d31fa8e96a4fa5d8ff8b0188dfb9e7c171bb";
}

const char* long_sha384() {
    return "d3b5710e17da84216f1bf08079bbbbf45303baefc6ecd677910a1c33c86cb1642"
        "81f0f2dcab55bbadc5e8606bdbc16b6";
}

const char* long_sha512() {
    return "8ba760cac29cb2b2ce66858ead169174057aa1298ccd581514e6db6dee3285280"
        "ee6e3a54c9319071dc8165ff061d77783100d449c937ff1fb4cd1bb516a69b9";
}

const char* long_ripemd160() {
    return "c4e3cc08809d907e233a24c10056c9951a67ffe2";
}

const char* hmac_md2() {
    return "2f4145529e20098f844838ed8fa25c00";
}

const char* hmac_md4() {
    return "8cf0fe3c2742db0c79887e2c7db38932";
}

const char* hmac_md5() {
    return "e6be7149bdf6c8ba909f73cf70f418bc";
}

const char* hmac_sha1() {
    return "e555abe5b1e4778d2b9a287ad54b307b23a9ae7f";
}

const char* hmac_sha224() {
    return "5e8ec017b64206dc1255cccfa9ba0855a7fe049e56a738ed8c8dbeba";
}

const char* hmac_sha256() {
    return "85844cded885971e6c58087c814cdee1780caa6c2cea491dd05b5e345f4e17d8";
}

const char* hmac_sha384() {
    return "c79079bdff18bab9d22cd7ef84a8a347491632e48543b2f6300400a7eb178246b"
        "f117703ad1ca8461d2f042b840edafd";
}

const char* hmac_sha512() {
    return "ad723f73a26e1002bc5b226457f88235a26226a4f5c755d048560f22bbd17b5d5"
        "a13920fff6d41ffecb5f6babcf29125bbed8e5caf0da7ff2d3f34f08715aba7";
}

const char* hmac_ripemd160() {
    return "d8a3cd3129090b0fff57f6ade2a33e2d67c4c0a2";
}

///////////////////////////////////////////////////////////////////////////////
} // namespace anon
///////////////////////////////////////////////////////////////////////////////

TEST_CASE("hash tests", "[hash]") {
    using namespace mbedcrypto;

    SECTION("size and single shot digest") {
        const buffer_t src(test::long_text());
        const buffer_t key(test::short_text());

        #if defined(MBEDTLS_MD2_C)
        REQUIRE( hash_size(hash_t::md2) == 16 );
        REQUIRE( to_hex(make_hash(hash_t::md2, src)) == long_md2() );
        REQUIRE( to_hex(make_hmac(hash_t::md2, key, src)) == hmac_md2() );
        #endif

        #if defined(MBEDTLS_MD4_C)
        REQUIRE( hash_size(hash_t::md4) == 16 );
        REQUIRE( to_hex(make_hash(hash_t::md4, src)) == long_md4() );
        REQUIRE( to_hex(make_hmac(hash_t::md4, key, src)) == hmac_md4() );
        #endif // MBEDTLS_MD4_C

        #if defined(MBEDTLS_MD5_C)
        REQUIRE( hash_size(hash_t::md5) == 16 );
        REQUIRE( to_hex(make_hash(hash_t::md5, src)) == long_md5() );
        REQUIRE( to_hex(make_hmac(hash_t::md5, key, src)) == hmac_md5() );
        #endif // MBEDTLS_MD5_C

        #if defined(MBEDTLS_SHA1_C)
        REQUIRE( hash_size(hash_t::sha1) == 20 );
        REQUIRE( to_hex(make_hash(hash_t::sha1, src)) == long_sha1() );
        REQUIRE( to_hex(make_hmac(hash_t::sha1, key, src)) == hmac_sha1() );
        #endif // MBEDTLS_SHA1_C

        #if defined(MBEDTLS_SHA256_C)
        REQUIRE( hash_size(hash_t::sha224) == 28 );
        REQUIRE( hash_size(hash_t::sha256) == 32 );
        REQUIRE( to_hex(make_hash(hash_t::sha224, src)) == long_sha224() );
        REQUIRE( to_hex(make_hash(hash_t::sha256, src)) == long_sha256() );
        REQUIRE( to_hex(make_hmac(hash_t::sha224, key, src)) == hmac_sha224() );
        REQUIRE( to_hex(make_hmac(hash_t::sha256, key, src)) == hmac_sha256() );
        #endif // MBEDTLS_SHA256_C

        #if defined(MBEDTLS_SHA512_C)
        REQUIRE( hash_size(hash_t::sha384) == 48 );
        REQUIRE( hash_size(hash_t::sha512) == 64 );
        REQUIRE( to_hex(make_hash(hash_t::sha384, src)) == long_sha384() );
        REQUIRE( to_hex(make_hash(hash_t::sha512, src)) == long_sha512() );
        REQUIRE( to_hex(make_hmac(hash_t::sha384, key, src)) == hmac_sha384() );
        REQUIRE( to_hex(make_hmac(hash_t::sha512, key, src)) == hmac_sha512() );
        #endif // MBEDTLS_SHA512_C

        #if defined(MBEDTLS_RIPEMD160_C)
        REQUIRE( hash_size(hash_t::ripemd160) == 20 );
        REQUIRE( to_hex(make_hash(hash_t::ripemd160, src)) == long_ripemd160() );
        REQUIRE( to_hex(make_hmac(hash_t::ripemd160, key, src)) == hmac_ripemd160() );
        #endif // MBEDTLS_RIPEMD160_C

    }

    SECTION("creation") {
        REQUIRE_THROWS( hash{hash_t::none} );
        REQUIRE_THROWS( hash{from_string<hash_t>("MD_what?")} );
        REQUIRE_NOTHROW( hash{hash_t::sha1} );
        REQUIRE_NOTHROW( hash{from_string<hash_t>("sha512")} );

        hash h1(hash_t::sha1);
        hash h2(from_string<hash_t>("MD5"));
    }
}
