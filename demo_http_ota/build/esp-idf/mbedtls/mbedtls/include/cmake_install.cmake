# Install script for directory: G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/main")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/sdk/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32s3-elf-objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/block_cipher.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/build_info.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-2.x.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_legacy_crypto.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_legacy_from_psa.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_psa_from_legacy.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_psa_superset_legacy.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_ssl.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_adjust_x509.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_psa.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/constant_time.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/lms.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/mbedtls_config.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs7.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/private_access.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/psa_util.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha3.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/build_info.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_auto_enabled.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_config_dependencies.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_config_key_pair_types.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_adjust_config_synonyms.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_composites.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_key_derivation.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_primitives.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_compat.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_config.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_common.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_key_derivation.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_extra.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_legacy.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_platform.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_se_driver.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_sizes.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_struct.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_types.h"
    "G:/Kteer_project/Kteer_project/ESP32/ESP_IDF_V5_4_1/v5.4.1/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_values.h"
    )
endif()

