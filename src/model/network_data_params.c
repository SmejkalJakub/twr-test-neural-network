/**
  ******************************************************************************
  * @file    network_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Mar 18 23:56:09 2023
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

#include "network_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_weights_array_u64[161] = {
  0xbe599e06bf59f3d8U, 0xbe983f4fbece7a3bU, 0xbe7d91c23d9d469cU, 0x3ef726ffbf8a7e72U,
  0x3fefdb4d3ed9ef65U, 0xbd4bb240bddfe310U, 0xbfa22f42bf05d6c7U, 0xbf903a273d99f4d0U,
  0xbea54019be79c5e2U, 0x3ed534c73eb55042U, 0xbe949bd1be790816U, 0x3ee1f852be7dfcbaU,
  0xbeb683babe8f1af4U, 0xbe146b1e3eb6038fU, 0xbe1bb3f6bc21ad80U, 0xbf028cb63e4ea97eU,
  0xbe78579cU, 0xbceee2ca3f069796U, 0x0U, 0xbf7ab39e00000000U,
  0x0U, 0x3e4df724U, 0x0U, 0xbe0d6065U,
  0x3ed43b5900000000U, 0x3ecae925be178110U, 0xbce74cc0ba89ea00U, 0xbf479b8e3ebd449bU,
  0xbec29cabbe2e8feaU, 0xbde900f43dda172fU, 0xbeb4ca2f3e7b5516U, 0xbecbbebf3ea95d0cU,
  0xbea52e693eb7a68fU, 0xbe4a091fbec423ecU, 0x3e9da241be75aefcU, 0x3e8d3ac33ed1bfddU,
  0x3e807383bebb96aaU, 0x3e470fb2bead7ca3U, 0xbe815fc63d4c0498U, 0xbe98449ebe9a5881U,
  0xbdfa2c6cbe005dbeU, 0x3e91760d3e0206cbU, 0x3e9b86113e8a9f1fU, 0xbe98d5c83e8cb03dU,
  0xbdc3b3d83e954e39U, 0x3e032b623dc2eb15U, 0x3e9e5db5bd313d20U, 0xbea94c253ec0a80eU,
  0x3e948bbf3eb28017U, 0x3e174aeebed51a86U, 0x3edd50bfbdca6188U, 0x3e96fe2d3ed0e051U,
  0xbe894dfbbe134b66U, 0xbe9ef230be0e28c4U, 0xbdce6c1cbce6c870U, 0x3ebeae91beba9201U,
  0xbe57d8b2bed4abccU, 0x3e376ddc3e0c1620U, 0xbe5b6536beb1ef49U, 0x3eb6ebc0be0c818eU,
  0x3ec389113d633950U, 0xbe0f743e3ea42eefU, 0x3e197d263e7b9b96U, 0xbeb1aacd3db9ad60U,
  0x3d9d2c94bec6e5c2U, 0x3e814be9bebe1725U, 0x3e8d8f7bbeca4f79U, 0x3d5bb210bebca3c1U,
  0x3e44a602be9869ccU, 0x3ddb59acbe80331aU, 0x3ed787df3dc9ecbcU, 0x3e5cb4f6be752588U,
  0xbeddb242be0d53a6U, 0xbf3fa3bf3e986d4bU, 0x3da151543e17ea62U, 0xbeaae4573e3a89feU,
  0x3e6178fabd06dd48U, 0x3ea1c333bee71eb0U, 0x3e4f2e82bc5ba3a0U, 0xbbea68c0be32dc3fU,
  0xbeadf1fcbe5f6f15U, 0x3eb6b12d3e342fbbU, 0x3d420868be8c3234U, 0x3da8f4223ea0200dU,
  0xbea945b43ed8acdbU, 0xbe9eecd5bea2923fU, 0x3e80c4293e0963faU, 0x3e1e78963eb99fb6U,
  0xbe99c1883ced83e0U, 0xbe99a591bdac2dfeU, 0x3dd0180cbd428fd0U, 0x3f154245bedc439eU,
  0xbed10d98beab92b2U, 0xbec1805e3eb0cd80U, 0x3ebf96473e874935U, 0xbe99a2debdd68c09U,
  0xbe5325d03ecccbefU, 0xbe87f3fa3f1df1beU, 0xbe8e0c12be58b97cU, 0xbfe001f8bd732788U,
  0x3e9ed971be8a2832U, 0xbed072713de420fdU, 0x3d247430be901e86U, 0xbd81b184bf03c380U,
  0x3e667f523d0ddf78U, 0xbeb511eebc6f6140U, 0x3cd67b80be452e60U, 0xbeb4677c3d3e7d78U,
  0x3ea7ba87beae47bcU, 0x3e2ce906be660d15U, 0x3dce558cbcf0e8f0U, 0x3e5ab98e3eac9dd3U,
  0x3e952699bd017c00U, 0x3e9deb99be12ad1aU, 0x3d96c694be8be624U, 0xbd14fac8be280abaU,
  0xbdf056f03ec87d33U, 0x3df5792cbec720e5U, 0x3cda9c503d2c8880U, 0xbe9ead08bd40b5c8U,
  0xbed78bbe3e8a9e1fU, 0xbddc6f74bed056b4U, 0xbdd6eaf83e0edc02U, 0x3ebd87e9be93c986U,
  0xbec947eebd6e58c8U, 0x3ec535073e62d0deU, 0x3eca8f5fbdd3cf6cU, 0x3c8c6600beac240eU,
  0x3ec9bbbb3d49a4a0U, 0xbf5a0d6c3e70cf88U, 0x3e2914b63eba1e7fU, 0x3e1f55213d54cc20U,
  0x3d8282903e5ce31aU, 0xbda7a200bebf50aeU, 0x3d9d81ecbec96ce9U, 0x3dc6df0c3e1e1b5cU,
  0x3e62dceabe33ccbcU, 0x3df4c334be15baeeU, 0xbe29f27ebd5ed6b8U, 0xbdde2ec4be6849daU,
  0x3da6783cbd8ac148U, 0xbe39ae06bec90264U, 0xbeaf9f3c3db8cbc4U, 0xbdc7362c3edd1655U,
  0x3d930e1cbcb08e10U, 0xbdcf59243ea2402dU, 0xbe27db4abe4ecf92U, 0xbf562491be7c10beU,
  0x3e121e823ea4ccc3U, 0xbe55e97ebc7ff990U, 0x3ed8db1d3eac6243U, 0xbdaba7343e3dbe03U,
  0x3ea03948be98e8b3U, 0x3e5bb47100000000U, 0xbee7149000000000U, 0x3edcf3f100000000U,
  0xbe824f66be651d57U, 0x3f94cd9bU, 0x0U, 0x3ee62748U,
  0x3f3e2d66U,
};


ai_handle g_network_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

