/**
  ******************************************************************************
  * @file    network_humidity_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Mar 19 22:16:27 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_humidity_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_humidity_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_humidity_weights_array_u64[217] = {
  0x3c9c1d40bb194187U, 0xbe6408d93d0f25a6U, 0xbf01e483be14a106U, 0x3e7abcbc3d6fa2c5U,
  0xbe34b43a3a8ca37eU, 0x3b9d59fbbd6a82c3U, 0x3d9321db3d89f07dU, 0xbf0cd0a53eee58dbU,
  0xbeefe3783ed0a33cU, 0x3ca71e403ee04454U, 0x3e386cf03efa02fcU, 0xbedbc338bedd7074U,
  0x3c20ca45be563080U, 0xbf026c1bbeb2fb3bU, 0x3e27e08cbe651911U, 0xbf1d39e0beb92d61U,
  0xbc82cf343d41fa16U, 0x3eb4d001be0f7b0aU, 0x3f130161be0b4dc3U, 0xbe60fb82be4f4abeU,
  0x3dc14c21bc93565dU, 0xbdc1a10fbdfab09aU, 0x3d440539bdba2a54U, 0x4004b1543d1949d2U,
  0xbe9f9b7cbf0929fcU, 0x3ee95ce4bdb4ccf0U, 0x3eac0808bed958c4U, 0x3eb155703d982140U,
  0xbbbb65f6bd010f60U, 0x3d9e7187bf0236b8U, 0x3de72ee5beaa7a28U, 0x3ee26027bf2c3e79U,
  0x3ced1e39bf1cc1fdU, 0xbf34fd273b085aa2U, 0x3cdd7ba8be738797U, 0xbfa593dc3d5b4c6cU,
  0xbbcde984bece5650U, 0xbc43ad303ee040aaU, 0xbe5bb250bedb5346U, 0x3dc8e7823b0b6841U,
  0x3d8d83c23e66a359U, 0xbe20751c3bad0eddU, 0x3bbb4267bdd72b97U, 0xc01f84a2bbc7fb92U,
  0x3ca040d2beb07fe9U, 0xbee5f57ebe74e8f2U, 0xbe82dcc53f10bf9fU, 0xbf147049bf1a246eU,
  0xbe051b50bf3f2abbU, 0x3e442dc83edb63d8U, 0xbccabb00bef5c78cU, 0xbe4783c0bee5b4dcU,
  0xbc2b97f93e4c2778U, 0x3e3ed81b3e6d8983U, 0xbeccfae2be19230cU, 0x3ffdea42bf30671dU,
  0x3c0b435a3e82fd41U, 0xbf101759be74f2edU, 0xbeaedd2ebf1a9900U, 0x3db81677becf2adcU,
  0x3c1c6c72befbba24U, 0x3d04f3ddbeb3c120U, 0xbe9ba348be3c8eb9U, 0xbedc2d2cbec8c3a8U,
  0xbef675fcbdac9b42U, 0xbe92a0403ef1c6d4U, 0xbe2df788be1b6be0U, 0x3ec3d7bc3eccd1a8U,
  0xbe41a9b8bef87320U, 0xbe904ea03ec02794U, 0xbec9a1903ee49a0cU, 0xbeb4dd88be5921d0U,
  0xbedb8258U, 0xbd6c4bc5bed27003U, 0xbe28798dU, 0xbe6c768bbeb8823cU,
  0xbbbb786fbd064737U, 0xbeb2e72cU, 0xbe228da3bd7418a1U, 0xbb4f3d5fU,
  0x3e81d23900000000U, 0xbe8bb9b13e79ee4cU, 0x3e67065ebce96ef5U, 0x3e7f0a51bc2eb74cU,
  0xbded8241be04501cU, 0xbe86e4b23e27fc69U, 0xbd0a42cf3dad2f88U, 0x3e6874aa3ea4419bU,
  0xbd1e6fa8be8a5a81U, 0x3eb66479bed69a30U, 0x3e7c6866be8348b3U, 0x3e9fc5f3bd5bd4f0U,
  0xbea81da23a872100U, 0x3e188d4ebe0a994eU, 0xbeb982d8bcd93dc0U, 0x3ebea1b5be832a0aU,
  0xbe1f2ad83e31b23aU, 0x3ebd2654bd6697acU, 0x3dc8a0e43e193d8aU, 0x3d6718ae3df33bfbU,
  0xbecb7302bec39fe4U, 0xbe9ba5653e26ca56U, 0xbe07856bbf1e13acU, 0x3c99b1103cd50e8eU,
  0x3ed5a8c1bd88af7cU, 0x3ed4e01d3eb520eaU, 0x3e3b6682bc023bddU, 0x3e2da2fbbcdfacb8U,
  0x3debb8d83ebb1456U, 0xbe608b313e44ad70U, 0x3e83da4fbf37a6f7U, 0xbed85effbe588ea5U,
  0x3e9703433e235a12U, 0xbd7519d13e34eb15U, 0xbe5122f6be82f9bcU, 0xbe7700d93e676670U,
  0x3e89a92b3e445a9dU, 0xbe208aeabe5d0f88U, 0x3ebcc3d6be8d066bU, 0x3e0df9d6bec9a449U,
  0x3e3db336bed3d46dU, 0x3e5021f6be93133aU, 0x3ec3c661bed6eb95U, 0x3dc8b94cbdf70370U,
  0x3ecb0a7bbe1a5940U, 0x3e4c13f63cf07740U, 0x3d8ff6acbea9e9edU, 0x3e91283fbdb4fe94U,
  0xbe2bef723edba30dU, 0x3ec6d7d8bcfc8e93U, 0xbcb701903c189a44U, 0x3ed81ec73e9bb114U,
  0x3eec50d7be6523bdU, 0xbe8ee9373e7ba091U, 0xbcfb1e48bf410b80U, 0x3e2892f23e16b0efU,
  0xbe8bac1ebe366476U, 0x3e9f7b413ef1afefU, 0xbecc7126be31b8caU, 0x3eee3bc2beb1062aU,
  0x3f4752bdbedda855U, 0xbe2ffd58bdf1eff2U, 0x3e80f8063e8fa6feU, 0xbe9fe4c9be660fa9U,
  0x3d9c23243e9ba26bU, 0x3ebe8b813e298c49U, 0x3c006660bf00ce1bU, 0xbc02cf073c28e3cbU,
  0x3ecec553beb3e2a1U, 0x3eca0d313e9f66a5U, 0x3c8b9252beb8cd94U, 0x3e128da23ec5ae86U,
  0xbe2238bc3eb10fc9U, 0xbe6fe1b3be9a3f59U, 0x3e543f8abeaa4582U, 0x3cc0f6803e864181U,
  0xbcc0b6e0bdedad60U, 0xbe2cd3b8bd185460U, 0x3e6d1ab23e7e6e66U, 0x3eae02df3da21c6cU,
  0xbd86646c3e87b809U, 0x3e7f5e143da92d97U, 0xbdbe334cbd2a7ebeU, 0x3e7c44563ca03d9aU,
  0xbe5efa3cbe49930cU, 0xbe819d2b3e670796U, 0xbe75e7a93eb856b8U, 0x3d006fa0be01cdf5U,
  0x3ea54efbbea02c08U, 0x3e27ee23be30ef63U, 0x3e20feeebeadde74U, 0xbdde47be3e29380eU,
  0xbf257c253e9a29b4U, 0x3e06b5663e70ac2aU, 0xbf062db73dd8d210U, 0x3dd7981c3e9f916aU,
  0xbc3b2480b9d50c00U, 0xbe19a01cbdad809dU, 0xbd93d334be614190U, 0x3e6b8a12be870aa9U,
  0x3e2bf8693e06825eU, 0x3d648c903eaa9cc5U, 0xbe551906be8e9417U, 0x3e9bf3b1bd59ebb8U,
  0x3e877123be9c59f6U, 0x3e9acbdb3e714cf7U, 0x3eab8129bc9559acU, 0xbdd82a3c3db29fd2U,
  0xbb7fd1713d1043b7U, 0xbea6ec4ebee8903aU, 0x3ec73837bcd17f06U, 0x3e8d66c13d78fd8dU,
  0x3df0f23c3ec784a5U, 0x3e7b2afd3eaa4472U, 0x3e0e25ee3eb5e929U, 0xbe3bd26fbd217823U,
  0xbf01cb8a3e56d233U, 0xbe9b0c2abdc409ddU, 0x3ea390f03de085beU, 0xbe17d6a2be0660b7U,
  0x3ecfa02f3e678cbaU, 0x3bf16940bedc9f1bU, 0x3eb8759bbe992f44U, 0x3ec85de9be6e1b7fU,
  0xbe87fcae3e874643U, 0xbe6ccee33d8fa7fcU, 0x3e4a5c6a3e0f9e36U, 0x3ed7f0373ed2905fU,
  0xbcf386583ed42597U, 0x3d05154700000000U, 0xbc0e8f45be7bbe9cU, 0xbd2b251500000000U,
  0xbd95e6c13c7ca0f0U, 0x3d8bf83600000000U, 0xbc1d47e3be508157U, 0x3e8fc1d8bda760e0U,
  0x0U,
};


ai_handle g_network_humidity_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_humidity_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

