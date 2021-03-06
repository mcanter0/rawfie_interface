/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _HOME_GLAMDRING_PRUEBAS_KAFKA_AVROCPPHEADERS_INCLUDE_STORAGE_USAGE_HH_159752136__H_
#define _HOME_GLAMDRING_PRUEBAS_KAFKA_AVROCPPHEADERS_INCLUDE_STORAGE_USAGE_HH_159752136__H_


#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"
#include "header.hh"


struct StorageUsage {
    Header header;
    int32_t available;
    int32_t value;
};

namespace avro {
template<> struct codec_traits<StorageUsage> {
    static void encode(Encoder& e, const StorageUsage& v) {
        avro::encode(e, v.header);
        avro::encode(e, v.available);
        avro::encode(e, v.value);
    }
    static void decode(Decoder& d, StorageUsage& v) {
        avro::decode(d, v.header);
        avro::decode(d, v.available);
        avro::decode(d, v.value);
    }
};

}
#endif
