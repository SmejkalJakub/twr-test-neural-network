/**
  ******************************************************************************
  * @file    network_temperature_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Mar 19 22:16:21 2023
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

#include "network_temperature_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_temperature_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_temperature_weights_array_u64[217] = {
  0x3a3a6c9ebf105728U, 0x3e6f335bbe1b60b1U, 0xbe3b17623ecefcfcU, 0x39c5f34abb90fe93U,
  0x3f086a6a3d9437e8U, 0xbee90ddd3ec705adU, 0xbe7a8fc0beef42c0U, 0x3e638455bac6d7dfU,
  0xbeada0f83eced922U, 0x3ef8af7c3dede690U, 0xbe038388bedf1dd0U, 0xbed093843ee2948cU,
  0x3cb7878d3dc82450U, 0x3e372bc43e0acd22U, 0x3e1098a1bc8b82f2U, 0xbfe9f49cbed8ded2U,
  0xbeef1a58befa7b38U, 0xbe2c46f8be343058U, 0xbee7e5acbe43bbf8U, 0xbed706f0be88d3c0U,
  0x3bcea1e53edb6010U, 0xbe3c8fddbf4b3643U, 0xbaa1f7663d00c857U, 0x403f5c84bb3ddf54U,
  0x3bf5b4d03c596b94U, 0xbf0ff70bbec9e342U, 0x3c7329c23e9820b4U, 0xbe2307e8bd824876U,
  0xbefdbf8cbe37308dU, 0xbee65cecbdca5150U, 0x3e484700be72e448U, 0xbe7d9fd83ed60808U,
  0xbbf9fa003ebb7f18U, 0xbdb0f1e03ecd2d50U, 0xbee7be143d3b6220U, 0x3e78a658bdcbe150U,
  0xbbe4750abe9e8a94U, 0xbe5caba9bd778ed2U, 0xbec44913be56b1e2U, 0x3c32e064bc3c638fU,
  0xbc4a5e163e9c0cfbU, 0xbf270909be6a4678U, 0x3dd7872c3e0ebeabU, 0xbe7aaf693eb10892U,
  0x3b2288943e913c50U, 0xbe4cd015be88b9bfU, 0xbe00b6733e225399U, 0xbda1d41dbeb53a87U,
  0xbe3d8208bcc2194eU, 0x3e765c103e805644U, 0xbe9ddc103e6d8c30U, 0x3efa8700bd208840U,
  0xbe27b260bd3ab000U, 0x3ec38ae43cff1280U, 0x3db32230be90ee24U, 0xbe7a8ea0be534988U,
  0x3bdd1405be292b90U, 0xbf0b36cd3db9548eU, 0xbe9702fabef2b11fU, 0xbde1d672bf179db2U,
  0xbd9831403b42943cU, 0xbeaa23583ea38c88U, 0xbef33200be005078U, 0x3da85ff03ef5e840U,
  0xbca76ff13e572310U, 0xbe70fd4cbf323371U, 0xbd4c8893be728e5fU, 0x4017f0443ca10430U,
  0xbeb96c80bea06431U, 0x3ec0a46cbef138e8U, 0x3e38aa703ebd2cf0U, 0x3e997a40be929c34U,
  0x3ea53f08U, 0xbe6ad8d1U, 0xbe10cdafbeadbd39U, 0x0U,
  0xbe44efccbc526283U, 0xbe133ac3U, 0xbe9155fb00000000U, 0xbedf8c7400000000U,
  0x3e9d9e1300000000U, 0xbe65e847be24c5b8U, 0x3edc3d67be46d937U, 0x3e95f8c9be2a45b6U,
  0xbe49a047bea2a746U, 0xbe0bc2fabec0b063U, 0xbe2754d6bcff6a70U, 0xbeadd5c83ec371d1U,
  0xbd43fab03c5d1b00U, 0xbed58cc23e3b3469U, 0x3e312e043b42c7bbU, 0x3ed759333d5cac08U,
  0xbe8bab9b3e83f16aU, 0xbcd8cd303e8d14ecU, 0xbeab2dd0bedcf81eU, 0xbdcdf7c2be8d9a6eU,
  0x3d333528bd1350b0U, 0xbd8d1c68bf556027U, 0x3d81bef03b48b475U, 0x3dbe75ec3e802e95U,
  0xbed4dcdcbe1e159cU, 0xbe91da66bee76c3aU, 0x3d38db8abeaa3a35U, 0xbf13f5113dabe154U,
  0x3eb7e4073e5a4772U, 0xbec8cb193df47407U, 0x3ec25d4d3e9fc727U, 0xbdb29458bedc0115U,
  0x3ec9103cbe4ceb84U, 0x3e2e950e3e17b0b6U, 0xbdd83e03be8d66c8U, 0xbea5144dbe579bfeU,
  0xbe697eb9be48279cU, 0xbd350ea83e7c95e4U, 0xbe76806ebe8c0f26U, 0xbe8999fa3e59071aU,
  0xbd6688b83e141f62U, 0x3e99e703bee0ffd6U, 0x3b4914703cc77ea0U, 0x3de92de5bd629d30U,
  0xbe6a62adbe9234dcU, 0x3eb0f64dbed85cc7U, 0x3e6f8276bedb59ceU, 0x3ddb61243e7b51e6U,
  0xbe67d57abbae4b40U, 0xbedda1f3be4ec479U, 0x3e8e3029be6a11c2U, 0x3ec0a027be5a570aU,
  0x3dc691e43e9f8b93U, 0x3e54cc6a3e12f16bU, 0x3e34e891bc1bf6d5U, 0x3ec557cf3ddc6494U,
  0x3edff2f1be2a3dfbU, 0x3ebc7c07be4e3987U, 0xbe01b26cbe88f4baU, 0x3d0db86b3dbfc854U,
  0x3e06e746bed49d7eU, 0x3ed347f1be8afac8U, 0xbe080d063b5a9f3cU, 0x3d1c1ed83e1f73b2U,
  0x3e7298f3bc63360cU, 0x3db5d7d43e93084fU, 0x3e9e0d3c3e0d0cbeU, 0xbfdb414d3ed8a32bU,
  0xbeb2f0ff3e95dd73U, 0x3ce101f0bea87042U, 0xbd940128bd5c59a8U, 0xbe3ff3e83dc5d6ccU,
  0x3d622b88be6bb61bU, 0xbed5f5b2bed1fb97U, 0x3d7a2980be837754U, 0xbe9f9a36bd330d88U,
  0x3e3ecd9e3e014ba2U, 0x3df55ec4bf41902cU, 0x3e16f562ba6048e4U, 0x3e432932beae765dU,
  0xbdf4f3b4bdf824e8U, 0x3eafde773da011fcU, 0x3e6f8fc6bec4d5fcU, 0xbe8febed3d0148b0U,
  0x3e394806be540647U, 0x3e342d1a3e109478U, 0xbe117e743eca07ccU, 0x3ed16fc1bd290a50U,
  0xbed147a0be654395U, 0x3e56221abe4d323fU, 0xbdf4255dbe938116U, 0x3e8f91a23ea3758fU,
  0x3edbb13b3ea02bbfU, 0x3eac1c93bea8fa3dU, 0x3e44ff26beb79a42U, 0x3eaebb4f3e9325dbU,
  0x3de7e0943eb87139U, 0xbe2e1d70bea109c9U, 0x3de69ef4bc8710f0U, 0x3e7f30063e79b4daU,
  0xbc1f7e80bea58d09U, 0xbe031aa6bdbe6604U, 0xbeaa7a5cbe6d35a5U, 0xbcd258d03e02a5beU,
  0xbec2a9d2bebcd321U, 0xbdd883083e8b4543U, 0xbe9099fcbe1266a8U, 0xbe55b334bd1a2df8U,
  0x3e862a71bd45b4e8U, 0xbe611ae6be684e91U, 0xbdb0b03cbcaf8525U, 0x3e7abe4a3e96493bU,
  0x3e7bba4ebe89c249U, 0x3e50badabd6a0b88U, 0xbebd20debe03f606U, 0x3eb8ee7dbe3c8a5bU,
  0xbe51603cbe5658e9U, 0x3e09e7c6bf6fe225U, 0xbe33fcaabb2cb203U, 0xbebcbf973ea6065dU,
  0x3e12d7eabe3b95ebU, 0xbd51db70bd8f20acU, 0x3ea22e0f3dd4fde4U, 0xbe26eb32bd8e5e5cU,
  0xbe84db7fbe711329U, 0x3c4ef240be353aafU, 0x3e2448963e9786e1U, 0xbec56996be3e39bfU,
  0x3ea8f4213df88a8fU, 0x3e8d12db3e006608U, 0xbebe40e0bea217baU, 0x3e1e22143e13c02eU,
  0x3e520aaeU, 0xbead0806bf07d492U, 0xbc8371fb3e2374f4U, 0xbec7ae2b00000000U,
  0xbf0e1e47U, 0x3e7b44bbbd6beaf2U, 0x0U, 0x3db3225ebe23bcc4U,
  0x3e247105U,
};


ai_handle g_network_temperature_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_temperature_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

