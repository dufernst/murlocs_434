/*
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup u2w
*/

#include "Opcodes.h"
#include "WorldSession.h"

static void DefineOpcode(uint16 opcode, const char* name, SessionStatus status, PacketProcessing packetProcessing, void (WorldSession::*handler)(WorldPacket& recvPacket))
{
    opcodeTable[opcode].name = name;
    opcodeTable[opcode].status = status;
    opcodeTable[opcode].packetProcessing = packetProcessing;
    opcodeTable[opcode].handler = handler;
}

#define OPCODE( name, status, packetProcessing, handler ) DefineOpcode( name, #name, status, packetProcessing, handler )

/// Correspondence between opcodes and their names
OpcodeHandler opcodeTable[MAX_OPCODE_TABLE_SIZE];

void InitializeOpcodes()
{
<<<<<<< HEAD
    /*0x000*/ { "MSG_NULL_ACTION",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x001*/ { "CMSG_BOOTME",                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x002*/ { "CMSG_DBLOOKUP",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x003*/ { "SMSG_DBLOOKUP",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x004*/ { "CMSG_QUERY_OBJECT_POSITION",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x005*/ { "SMSG_QUERY_OBJECT_POSITION",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x006*/ { "CMSG_QUERY_OBJECT_ROTATION",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x007*/ { "SMSG_QUERY_OBJECT_ROTATION",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x008*/ { "CMSG_WORLD_TELEPORT",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWorldTeleportOpcode       },
    /*0x009*/ { "CMSG_TELEPORT_TO_UNIT",                        STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x00A*/ { "CMSG_ZONE_MAP",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x00B*/ { "SMSG_ZONE_MAP",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x00C*/ { "CMSG_DEBUG_CHANGECELLZONE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x00D*/ { "CMSG_MOVE_CHARACTER_CHEAT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x00E*/ { "SMSG_MOVE_CHARACTER_CHEAT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x00F*/ { "CMSG_RECHARGE",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x010*/ { "CMSG_LEARN_SPELL",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x011*/ { "CMSG_CREATEMONSTER",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x012*/ { "CMSG_DESTROYMONSTER",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x013*/ { "CMSG_CREATEITEM",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x014*/ { "CMSG_CREATEGAMEOBJECT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x015*/ { "SMSG_CHECK_FOR_BOTS",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x016*/ { "CMSG_MAKEMONSTERATTACKGUID",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x017*/ { "CMSG_BOT_DETECTED2",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x018*/ { "CMSG_FORCEACTION",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x019*/ { "CMSG_FORCEACTIONONOTHER",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x01A*/ { "CMSG_FORCEACTIONSHOW",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x01B*/ { "SMSG_FORCEACTIONSHOW",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x01C*/ { "CMSG_PETGODMODE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x01D*/ { "SMSG_PETGODMODE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x01E*/ { "SMSG_REFER_A_FRIEND_EXPIRED",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x01F*/ { "CMSG_WEATHER_SPEED_CHEAT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x020*/ { "CMSG_UNDRESSPLAYER",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x021*/ { "CMSG_BEASTMASTER",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x022*/ { "CMSG_GODMODE",                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x023*/ { "SMSG_GODMODE",                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x024*/ { "CMSG_CHEAT_SETMONEY",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x025*/ { "CMSG_LEVEL_CHEAT",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x026*/ { "CMSG_PET_LEVEL_CHEAT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x027*/ { "CMSG_SET_WORLDSTATE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x028*/ { "CMSG_COOLDOWN_CHEAT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x029*/ { "CMSG_USE_SKILL_CHEAT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x02A*/ { "CMSG_FLAG_QUEST",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x02B*/ { "CMSG_FLAG_QUEST_FINISH",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x02C*/ { "CMSG_CLEAR_QUEST",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x02D*/ { "CMSG_SEND_EVENT",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x02E*/ { "CMSG_DEBUG_AISTATE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x02F*/ { "SMSG_DEBUG_AISTATE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x030*/ { "CMSG_DISABLE_PVP_CHEAT",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x031*/ { "CMSG_ADVANCE_SPAWN_TIME",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x032*/ { "SMSG_DESTRUCTIBLE_BUILDING_DAMAGE",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x033*/ { "CMSG_AUTH_SRP6_BEGIN",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x034*/ { "CMSG_AUTH_SRP6_PROOF",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x035*/ { "CMSG_AUTH_SRP6_RECODE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x036*/ { "CMSG_CHAR_CREATE",                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharCreateOpcode          },
    /*0x037*/ { "CMSG_CHAR_ENUM",                               STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharEnumOpcode            },
    /*0x038*/ { "CMSG_CHAR_DELETE",                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharDeleteOpcode          },
    /*0x039*/ { "SMSG_AUTH_SRP6_RESPONSE",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x03A*/ { "SMSG_CHAR_CREATE",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x03B*/ { "SMSG_CHAR_ENUM",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x03C*/ { "SMSG_CHAR_DELETE",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x03D*/ { "CMSG_PLAYER_LOGIN",                            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLoginOpcode         },
    /*0x03E*/ { "SMSG_NEW_WORLD",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x03F*/ { "SMSG_TRANSFER_PENDING",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x040*/ { "SMSG_TRANSFER_ABORTED",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x041*/ { "SMSG_CHARACTER_LOGIN_FAILED",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x042*/ { "SMSG_LOGIN_SETTIMESPEED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x043*/ { "SMSG_GAMETIME_UPDATE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x044*/ { "CMSG_GAMETIME_SET",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x045*/ { "SMSG_GAMETIME_SET",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x046*/ { "CMSG_GAMESPEED_SET",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x047*/ { "SMSG_GAMESPEED_SET",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x048*/ { "CMSG_SERVERTIME",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x049*/ { "SMSG_SERVERTIME",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x04A*/ { "CMSG_PLAYER_LOGOUT",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLogoutOpcode        },
    /*0x04B*/ { "CMSG_LOGOUT_REQUEST",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutRequestOpcode       },
    /*0x04C*/ { "SMSG_LOGOUT_RESPONSE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x04D*/ { "SMSG_LOGOUT_COMPLETE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x04E*/ { "CMSG_LOGOUT_CANCEL",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutCancelOpcode        },
    /*0x04F*/ { "SMSG_LOGOUT_CANCEL_ACK",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x050*/ { "CMSG_NAME_QUERY",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNameQueryOpcode           },
    /*0x051*/ { "SMSG_NAME_QUERY_RESPONSE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x052*/ { "CMSG_PET_NAME_QUERY",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetNameQueryOpcode        },
    /*0x053*/ { "SMSG_PET_NAME_QUERY_RESPONSE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x054*/ { "CMSG_GUILD_QUERY",                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleGuildQueryOpcode          },
    /*0x055*/ { "SMSG_GUILD_QUERY_RESPONSE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x056*/ { "CMSG_ITEM_QUERY_SINGLE",                       STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleItemQuerySingleOpcode     },
    /*0x057*/ { "CMSG_ITEM_QUERY_MULTIPLE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x058*/ { "SMSG_ITEM_QUERY_SINGLE_RESPONSE",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x059*/ { "SMSG_ITEM_QUERY_MULTIPLE_RESPONSE",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x05A*/ { "CMSG_PAGE_TEXT_QUERY",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePageTextQueryOpcode       },
    /*0x05B*/ { "SMSG_PAGE_TEXT_QUERY_RESPONSE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x05C*/ { "CMSG_QUEST_QUERY",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestQueryOpcode          },
    /*0x05D*/ { "SMSG_QUEST_QUERY_RESPONSE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x05E*/ { "CMSG_GAMEOBJECT_QUERY",                        STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleGameObjectQueryOpcode     },
    /*0x05F*/ { "SMSG_GAMEOBJECT_QUERY_RESPONSE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x060*/ { "CMSG_CREATURE_QUERY",                          STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleCreatureQueryOpcode       },
    /*0x061*/ { "SMSG_CREATURE_QUERY_RESPONSE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x062*/ { "CMSG_WHO",                                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoOpcode                 },
    /*0x063*/ { "SMSG_WHO",                                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x064*/ { "CMSG_WHOIS",                                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoisOpcode               },
    /*0x065*/ { "SMSG_WHOIS",                                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x066*/ { "CMSG_CONTACT_LIST",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleContactListOpcode         },
    /*0x067*/ { "SMSG_CONTACT_LIST",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x068*/ { "SMSG_FRIEND_STATUS",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x069*/ { "CMSG_ADD_FRIEND",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAddFriendOpcode           },
    /*0x06A*/ { "CMSG_DEL_FRIEND",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDelFriendOpcode           },
    /*0x06B*/ { "CMSG_SET_CONTACT_NOTES",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetContactNotesOpcode     },
    /*0x06C*/ { "CMSG_ADD_IGNORE",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAddIgnoreOpcode           },
    /*0x06D*/ { "CMSG_DEL_IGNORE",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDelIgnoreOpcode           },
    /*0x06E*/ { "CMSG_GROUP_INVITE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupInviteOpcode         },
    /*0x06F*/ { "SMSG_GROUP_INVITE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x070*/ { "CMSG_GROUP_CANCEL",                            STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x071*/ { "SMSG_GROUP_CANCEL",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x072*/ { "CMSG_GROUP_ACCEPT",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAcceptOpcode         },
    /*0x073*/ { "CMSG_GROUP_DECLINE",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDeclineOpcode        },
    /*0x074*/ { "SMSG_GROUP_DECLINE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x075*/ { "CMSG_GROUP_UNINVITE",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteOpcode       },
    /*0x076*/ { "CMSG_GROUP_UNINVITE_GUID",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteGuidOpcode   },
    /*0x077*/ { "SMSG_GROUP_UNINVITE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x078*/ { "CMSG_GROUP_SET_LEADER",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupSetLeaderOpcode      },
    /*0x079*/ { "SMSG_GROUP_SET_LEADER",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x07A*/ { "CMSG_LOOT_METHOD",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMethodOpcode          },
    /*0x07B*/ { "CMSG_GROUP_DISBAND",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDisbandOpcode        },
    /*0x07C*/ { "SMSG_GROUP_DESTROYED",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x07D*/ { "SMSG_GROUP_LIST",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x07E*/ { "SMSG_PARTY_MEMBER_STATS",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x07F*/ { "SMSG_PARTY_COMMAND_RESULT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x080*/ { "UMSG_UPDATE_GROUP_MEMBERS",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x081*/ { "CMSG_GUILD_CREATE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildCreateOpcode         },
    /*0x082*/ { "CMSG_GUILD_INVITE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInviteOpcode         },
    /*0x083*/ { "SMSG_GUILD_INVITE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x084*/ { "CMSG_GUILD_ACCEPT",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAcceptOpcode         },
    /*0x085*/ { "CMSG_GUILD_DECLINE",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDeclineOpcode        },
    /*0x086*/ { "SMSG_GUILD_DECLINE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x087*/ { "CMSG_GUILD_INFO",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInfoOpcode           },
    /*0x088*/ { "SMSG_GUILD_INFO",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x089*/ { "CMSG_GUILD_ROSTER",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRosterOpcode         },
    /*0x08A*/ { "SMSG_GUILD_ROSTER",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x08B*/ { "CMSG_GUILD_PROMOTE",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPromoteOpcode        },
    /*0x08C*/ { "CMSG_GUILD_DEMOTE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDemoteOpcode         },
    /*0x08D*/ { "CMSG_GUILD_LEAVE",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaveOpcode          },
    /*0x08E*/ { "CMSG_GUILD_REMOVE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRemoveOpcode         },
    /*0x08F*/ { "CMSG_GUILD_DISBAND",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDisbandOpcode        },
    /*0x090*/ { "CMSG_GUILD_LEADER",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaderOpcode         },
    /*0x091*/ { "CMSG_GUILD_MOTD",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildMOTDOpcode           },
    /*0x092*/ { "SMSG_GUILD_EVENT",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x093*/ { "SMSG_GUILD_COMMAND_RESULT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x094*/ { "UMSG_UPDATE_GUILD",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x095*/ { "CMSG_MESSAGECHAT",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode         },
    /*0x096*/ { "SMSG_MESSAGECHAT",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x097*/ { "CMSG_JOIN_CHANNEL",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleJoinChannelOpcode         },
    /*0x098*/ { "CMSG_LEAVE_CHANNEL",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveChannelOpcode        },
    /*0x099*/ { "SMSG_CHANNEL_NOTIFY",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x09A*/ { "CMSG_CHANNEL_LIST",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelListOpcode         },
    /*0x09B*/ { "SMSG_CHANNEL_LIST",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x09C*/ { "CMSG_CHANNEL_PASSWORD",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelPasswordOpcode     },
    /*0x09D*/ { "CMSG_CHANNEL_SET_OWNER",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelSetOwnerOpcode     },
    /*0x09E*/ { "CMSG_CHANNEL_OWNER",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelOwnerOpcode        },
    /*0x09F*/ { "CMSG_CHANNEL_MODERATOR",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelModeratorOpcode    },
    /*0x0A0*/ { "CMSG_CHANNEL_UNMODERATOR",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmoderatorOpcode  },
    /*0x0A1*/ { "CMSG_CHANNEL_MUTE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelMuteOpcode         },
    /*0x0A2*/ { "CMSG_CHANNEL_UNMUTE",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmuteOpcode       },
    /*0x0A3*/ { "CMSG_CHANNEL_INVITE",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelInviteOpcode       },
    /*0x0A4*/ { "CMSG_CHANNEL_KICK",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelKickOpcode         },
    /*0x0A5*/ { "CMSG_CHANNEL_BAN",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelBanOpcode          },
    /*0x0A6*/ { "CMSG_CHANNEL_UNBAN",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnbanOpcode        },
    /*0x0A7*/ { "CMSG_CHANNEL_ANNOUNCEMENTS",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelAnnouncementsOpcode},
    /*0x0A8*/ { "CMSG_CHANNEL_MODERATE",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelModerateOpcode     },
    /*0x0A9*/ { "SMSG_UPDATE_OBJECT",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0AA*/ { "SMSG_DESTROY_OBJECT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0AB*/ { "CMSG_USE_ITEM",                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUseItemOpcode             },
    /*0x0AC*/ { "CMSG_OPEN_ITEM",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOpenItemOpcode            },
    /*0x0AD*/ { "CMSG_READ_ITEM",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReadItemOpcode            },
    /*0x0AE*/ { "SMSG_READ_ITEM_OK",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0AF*/ { "SMSG_READ_ITEM_FAILED",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0B0*/ { "SMSG_ITEM_COOLDOWN",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0B1*/ { "CMSG_GAMEOBJ_USE",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameObjectUseOpcode       },
    /*0x0B2*/ { "CMSG_DESTROY_ITEMS",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0B3*/ { "SMSG_GAMEOBJECT_CUSTOM_ANIM",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0B4*/ { "CMSG_AREATRIGGER",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaTriggerOpcode         },
    /*0x0B5*/ { "MSG_MOVE_START_FORWARD",                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0B6*/ { "MSG_MOVE_START_BACKWARD",                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0B7*/ { "MSG_MOVE_STOP",                                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0B8*/ { "MSG_MOVE_START_STRAFE_LEFT",                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0B9*/ { "MSG_MOVE_START_STRAFE_RIGHT",                  STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0BA*/ { "MSG_MOVE_STOP_STRAFE",                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0BB*/ { "MSG_MOVE_JUMP",                                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0BC*/ { "MSG_MOVE_START_TURN_LEFT",                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0BD*/ { "MSG_MOVE_START_TURN_RIGHT",                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0BE*/ { "MSG_MOVE_STOP_TURN",                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0BF*/ { "MSG_MOVE_START_PITCH_UP",                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0C0*/ { "MSG_MOVE_START_PITCH_DOWN",                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0C1*/ { "MSG_MOVE_STOP_PITCH",                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0C2*/ { "MSG_MOVE_SET_RUN_MODE",                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0C3*/ { "MSG_MOVE_SET_WALK_MODE",                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0C4*/ { "MSG_MOVE_TOGGLE_LOGGING",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0C5*/ { "MSG_MOVE_TELEPORT",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0C6*/ { "MSG_MOVE_TELEPORT_CHEAT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0C7*/ { "MSG_MOVE_TELEPORT_ACK",                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveTeleportAckOpcode     },
    /*0x0C8*/ { "MSG_MOVE_TOGGLE_FALL_LOGGING",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0C9*/ { "MSG_MOVE_FALL_LAND",                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0CA*/ { "MSG_MOVE_START_SWIM",                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0CB*/ { "MSG_MOVE_STOP_SWIM",                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0CC*/ { "MSG_MOVE_SET_RUN_SPEED_CHEAT",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0CD*/ { "MSG_MOVE_SET_RUN_SPEED",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0CE*/ { "MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0CF*/ { "MSG_MOVE_SET_RUN_BACK_SPEED",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D0*/ { "MSG_MOVE_SET_WALK_SPEED_CHEAT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D1*/ { "MSG_MOVE_SET_WALK_SPEED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D2*/ { "MSG_MOVE_SET_SWIM_SPEED_CHEAT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D3*/ { "MSG_MOVE_SET_SWIM_SPEED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D4*/ { "MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D5*/ { "MSG_MOVE_SET_SWIM_BACK_SPEED",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D6*/ { "MSG_MOVE_SET_ALL_SPEED_CHEAT",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D7*/ { "MSG_MOVE_SET_TURN_RATE_CHEAT",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D8*/ { "MSG_MOVE_SET_TURN_RATE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0D9*/ { "MSG_MOVE_TOGGLE_COLLISION_CHEAT",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0DA*/ { "MSG_MOVE_SET_FACING",                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0DB*/ { "MSG_MOVE_SET_PITCH",                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0DC*/ { "MSG_MOVE_WORLDPORT_ACK",                       STATUS_TRANSFER, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveWorldportAckOpcode    },
    /*0x0DD*/ { "SMSG_MONSTER_MOVE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0DE*/ { "SMSG_MOVE_WATER_WALK",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0DF*/ { "SMSG_MOVE_LAND_WALK",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0E0*/ { "CMSG_MOVE_CHARM_PORT_CHEAT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0E1*/ { "CMSG_MOVE_SET_RAW_POSITION",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0E2*/ { "SMSG_FORCE_RUN_SPEED_CHANGE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0E3*/ { "CMSG_FORCE_RUN_SPEED_CHANGE_ACK",              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x0E4*/ { "SMSG_FORCE_RUN_BACK_SPEED_CHANGE",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0E5*/ { "CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK",         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x0E6*/ { "SMSG_FORCE_SWIM_SPEED_CHANGE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0E7*/ { "CMSG_FORCE_SWIM_SPEED_CHANGE_ACK",             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x0E8*/ { "SMSG_FORCE_MOVE_ROOT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0E9*/ { "CMSG_FORCE_MOVE_ROOT_ACK",                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveRootAck               },
    /*0x0EA*/ { "SMSG_FORCE_MOVE_UNROOT",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0EB*/ { "CMSG_FORCE_MOVE_UNROOT_ACK",                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveUnRootAck             },
    /*0x0EC*/ { "MSG_MOVE_ROOT",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0ED*/ { "MSG_MOVE_UNROOT",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0EE*/ { "MSG_MOVE_HEARTBEAT",                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x0EF*/ { "SMSG_MOVE_KNOCK_BACK",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0F0*/ { "CMSG_MOVE_KNOCK_BACK_ACK",                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveKnockBackAck          },
    /*0x0F1*/ { "MSG_MOVE_KNOCK_BACK",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0F2*/ { "SMSG_MOVE_FEATHER_FALL",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0F3*/ { "SMSG_MOVE_NORMAL_FALL",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0F4*/ { "SMSG_MOVE_SET_HOVER",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0F5*/ { "SMSG_MOVE_UNSET_HOVER",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0F6*/ { "CMSG_MOVE_HOVER_ACK",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveHoverAck              },
    /*0x0F7*/ { "MSG_MOVE_HOVER",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0F8*/ { "CMSG_TRIGGER_CINEMATIC_CHEAT",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0F9*/ { "CMSG_OPENING_CINEMATIC",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x0FA*/ { "SMSG_TRIGGER_CINEMATIC",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0FB*/ { "CMSG_NEXT_CINEMATIC_CAMERA",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNextCinematicCamera       },
    /*0x0FC*/ { "CMSG_COMPLETE_CINEMATIC",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCompleteCinematic         },
    /*0x0FD*/ { "SMSG_TUTORIAL_FLAGS",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x0FE*/ { "CMSG_TUTORIAL_FLAG",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialFlagOpcode        },
    /*0x0FF*/ { "CMSG_TUTORIAL_CLEAR",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialClearOpcode       },
    /*0x100*/ { "CMSG_TUTORIAL_RESET",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialResetOpcode       },
    /*0x101*/ { "CMSG_STANDSTATECHANGE",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStandStateChangeOpcode    },
    /*0x102*/ { "CMSG_EMOTE",                                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEmoteOpcode               },
    /*0x103*/ { "SMSG_EMOTE",                                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x104*/ { "CMSG_TEXT_EMOTE",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTextEmoteOpcode           },
    /*0x105*/ { "SMSG_TEXT_EMOTE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x106*/ { "CMSG_AUTOEQUIP_GROUND_ITEM",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x107*/ { "CMSG_AUTOSTORE_GROUND_ITEM",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x108*/ { "CMSG_AUTOSTORE_LOOT_ITEM",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutostoreLootItemOpcode   },
    /*0x109*/ { "CMSG_STORE_LOOT_IN_SLOT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x10A*/ { "CMSG_AUTOEQUIP_ITEM",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemOpcode       },
    /*0x10B*/ { "CMSG_AUTOSTORE_BAG_ITEM",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBagItemOpcode    },
    /*0x10C*/ { "CMSG_SWAP_ITEM",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapItem                  },
    /*0x10D*/ { "CMSG_SWAP_INV_ITEM",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapInvItemOpcode         },
    /*0x10E*/ { "CMSG_SPLIT_ITEM",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSplitItemOpcode           },
    /*0x10F*/ { "CMSG_AUTOEQUIP_ITEM_SLOT",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemSlotOpcode   },
    /*0x110*/ { "CMSG_UNCLAIM_LICENSE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x111*/ { "CMSG_DESTROYITEM",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDestroyItemOpcode         },
    /*0x112*/ { "SMSG_INVENTORY_CHANGE_FAILURE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x113*/ { "SMSG_OPEN_CONTAINER",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x114*/ { "CMSG_INSPECT",                                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectOpcode             },
    /*0x115*/ { "SMSG_INSPECT_RESULTS_UPDATE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x116*/ { "CMSG_INITIATE_TRADE",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInitiateTradeOpcode       },
    /*0x117*/ { "CMSG_BEGIN_TRADE",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBeginTradeOpcode          },
    /*0x118*/ { "CMSG_BUSY_TRADE",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBusyTradeOpcode           },
    /*0x119*/ { "CMSG_IGNORE_TRADE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleIgnoreTradeOpcode         },
    /*0x11A*/ { "CMSG_ACCEPT_TRADE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAcceptTradeOpcode         },
    /*0x11B*/ { "CMSG_UNACCEPT_TRADE",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnacceptTradeOpcode       },
    /*0x11C*/ { "CMSG_CANCEL_TRADE",                            STATUS_LOGGEDIN_OR_RECENTLY_LOGGEDOUT, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTradeOpcode},
    /*0x11D*/ { "CMSG_SET_TRADE_ITEM",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeItemOpcode        },
    /*0x11E*/ { "CMSG_CLEAR_TRADE_ITEM",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleClearTradeItemOpcode      },
    /*0x11F*/ { "CMSG_SET_TRADE_GOLD",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeGoldOpcode        },
    /*0x120*/ { "SMSG_TRADE_STATUS",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x121*/ { "SMSG_TRADE_STATUS_EXTENDED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x122*/ { "SMSG_INITIALIZE_FACTIONS",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x123*/ { "SMSG_SET_FACTION_VISIBLE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x124*/ { "SMSG_SET_FACTION_STANDING",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x125*/ { "CMSG_SET_FACTION_ATWAR",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionAtWarOpcode           },
    /*0x126*/ { "CMSG_SET_FACTION_CHEAT",                       STATUS_NEVER,    PROCESS_THREADUNSAFE, &WorldSession::Handle_Deprecated               },
    /*0x127*/ { "SMSG_SET_PROFICIENCY",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x128*/ { "CMSG_SET_ACTION_BUTTON",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionButtonOpcode     },
    /*0x129*/ { "SMSG_ACTION_BUTTONS",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x12A*/ { "SMSG_INITIAL_SPELLS",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x12B*/ { "SMSG_LEARNED_SPELL",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x12C*/ { "SMSG_SUPERCEDED_SPELL",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x12D*/ { "CMSG_NEW_SPELL_SLOT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x12E*/ { "CMSG_CAST_SPELL",                              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleCastSpellOpcode           },
    /*0x12F*/ { "CMSG_CANCEL_CAST",                             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleCancelCastOpcode          },
    /*0x130*/ { "SMSG_CAST_FAILED",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x131*/ { "SMSG_SPELL_START",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x132*/ { "SMSG_SPELL_GO",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x133*/ { "SMSG_SPELL_FAILURE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x134*/ { "SMSG_SPELL_COOLDOWN",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x135*/ { "SMSG_COOLDOWN_EVENT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x136*/ { "CMSG_CANCEL_AURA",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelAuraOpcode          },
    /*0x137*/ { "SMSG_EQUIPMENT_SET_ID",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x138*/ { "SMSG_PET_CAST_FAILED",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x139*/ { "MSG_CHANNEL_START",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x13A*/ { "MSG_CHANNEL_UPDATE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x13B*/ { "CMSG_CANCEL_CHANNELLING",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelChanneling          },
    /*0x13C*/ { "SMSG_AI_REACTION",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x13D*/ { "CMSG_SET_SELECTION",                           STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetSelectionOpcode        },
    /*0x13E*/ { "CMSG_DELETEEQUIPMENT_SET",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetDeleteOpcode  },
    /*0x13F*/ { "CMSG_INSTANCE_LOCK_RESPONSE",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInstanceLockResponse      },
    /*0x140*/ { "CMSG_DEBUG_PASSIVE_AURA",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x141*/ { "CMSG_ATTACKSWING",                             STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleAttackSwingOpcode         },
    /*0x142*/ { "CMSG_ATTACKSTOP",                              STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleAttackStopOpcode          },
    /*0x143*/ { "SMSG_ATTACKSTART",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x144*/ { "SMSG_ATTACKSTOP",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x145*/ { "SMSG_ATTACKSWING_NOTINRANGE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x146*/ { "SMSG_ATTACKSWING_BADFACING",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x147*/ { "SMSG_PENDING_RAID_LOCK",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x148*/ { "SMSG_ATTACKSWING_DEADTARGET",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x149*/ { "SMSG_ATTACKSWING_CANT_ATTACK",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x14A*/ { "SMSG_ATTACKERSTATEUPDATE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x14B*/ { "SMSG_BATTLEFIELD_PORT_DENIED",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x14C*/ { "CMSG_PERFORM_ACTION_SET",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x14D*/ { "SMSG_RESUME_CAST_BAR",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x14E*/ { "SMSG_CANCEL_COMBAT",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x14F*/ { "SMSG_SPELLBREAKLOG",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x150*/ { "SMSG_SPELLHEALLOG",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x151*/ { "SMSG_SPELLENERGIZELOG",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x152*/ { "SMSG_BREAK_TARGET",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x153*/ { "CMSG_SAVE_PLAYER",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x154*/ { "CMSG_SETDEATHBINDPOINT",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x155*/ { "SMSG_BINDPOINTUPDATE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x156*/ { "CMSG_GETDEATHBINDZONE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x157*/ { "SMSG_BINDZONEREPLY",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x158*/ { "SMSG_PLAYERBOUND",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x159*/ { "SMSG_CLIENT_CONTROL_UPDATE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x15A*/ { "CMSG_REPOP_REQUEST",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepopRequestOpcode        },
    /*0x15B*/ { "SMSG_RESURRECT_REQUEST",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x15C*/ { "CMSG_RESURRECT_RESPONSE",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleResurrectResponseOpcode   },
    /*0x15D*/ { "CMSG_LOOT",                                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootOpcode                },
    /*0x15E*/ { "CMSG_LOOT_MONEY",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMoneyOpcode           },
    /*0x15F*/ { "CMSG_LOOT_RELEASE",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootReleaseOpcode         },
    /*0x160*/ { "SMSG_LOOT_RESPONSE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x161*/ { "SMSG_LOOT_RELEASE_RESPONSE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x162*/ { "SMSG_LOOT_REMOVED",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x163*/ { "SMSG_LOOT_MONEY_NOTIFY",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x164*/ { "SMSG_LOOT_ITEM_NOTIFY",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x165*/ { "SMSG_LOOT_CLEAR_MONEY",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x166*/ { "SMSG_ITEM_PUSH_RESULT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x167*/ { "SMSG_DUEL_REQUESTED",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x168*/ { "SMSG_DUEL_OUTOFBOUNDS",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x169*/ { "SMSG_DUEL_INBOUNDS",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x16A*/ { "SMSG_DUEL_COMPLETE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x16B*/ { "SMSG_DUEL_WINNER",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x16C*/ { "CMSG_DUEL_ACCEPTED",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelAcceptedOpcode        },
    /*0x16D*/ { "CMSG_DUEL_CANCELLED",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelCancelledOpcode       },
    /*0x16E*/ { "SMSG_MOUNTRESULT",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x16F*/ { "SMSG_DISMOUNTRESULT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x170*/ { "SMSG_REMOVED_FROM_PVP_QUEUE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x171*/ { "CMSG_MOUNTSPECIAL_ANIM",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMountSpecialAnimOpcode    },
    /*0x172*/ { "SMSG_MOUNTSPECIAL_ANIM",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x173*/ { "SMSG_PET_TAME_FAILURE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x174*/ { "CMSG_PET_SET_ACTION",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSetAction              },
    /*0x175*/ { "CMSG_PET_ACTION",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAction                 },
    /*0x176*/ { "CMSG_PET_ABANDON",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAbandon                },
    /*0x177*/ { "CMSG_PET_RENAME",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetRename                 },
    /*0x178*/ { "SMSG_PET_NAME_INVALID",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x179*/ { "SMSG_PET_SPELLS",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x17A*/ { "SMSG_PET_MODE",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x17B*/ { "CMSG_GOSSIP_HELLO",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipHelloOpcode         },
    /*0x17C*/ { "CMSG_GOSSIP_SELECT_OPTION",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipSelectOptionOpcode  },
    /*0x17D*/ { "SMSG_GOSSIP_MESSAGE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x17E*/ { "SMSG_GOSSIP_COMPLETE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x17F*/ { "CMSG_NPC_TEXT_QUERY",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNpcTextQueryOpcode        },
    /*0x180*/ { "SMSG_NPC_TEXT_UPDATE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x181*/ { "SMSG_NPC_WONT_TALK",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x182*/ { "CMSG_QUESTGIVER_STATUS_QUERY",                 STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleQuestgiverStatusQueryOpcode},
    /*0x183*/ { "SMSG_QUESTGIVER_STATUS",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x184*/ { "CMSG_QUESTGIVER_HELLO",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverHelloOpcode     },
    /*0x185*/ { "SMSG_QUESTGIVER_QUEST_LIST",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x186*/ { "CMSG_QUESTGIVER_QUERY_QUEST",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQueryQuestOpcode},
    /*0x187*/ { "CMSG_QUESTGIVER_QUEST_AUTOLAUNCH",             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQuestAutoLaunch },
    /*0x188*/ { "SMSG_QUESTGIVER_QUEST_DETAILS",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x189*/ { "CMSG_QUESTGIVER_ACCEPT_QUEST",                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverAcceptQuestOpcode},
    /*0x18A*/ { "CMSG_QUESTGIVER_COMPLETE_QUEST",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCompleteQuest   },
    /*0x18B*/ { "SMSG_QUESTGIVER_REQUEST_ITEMS",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x18C*/ { "CMSG_QUESTGIVER_REQUEST_REWARD",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverRequestRewardOpcode},
    /*0x18D*/ { "SMSG_QUESTGIVER_OFFER_REWARD",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x18E*/ { "CMSG_QUESTGIVER_CHOOSE_REWARD",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverChooseRewardOpcode},
    /*0x18F*/ { "SMSG_QUESTGIVER_QUEST_INVALID",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x190*/ { "CMSG_QUESTGIVER_CANCEL",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCancel          },
    /*0x191*/ { "SMSG_QUESTGIVER_QUEST_COMPLETE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x192*/ { "SMSG_QUESTGIVER_QUEST_FAILED",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x193*/ { "CMSG_QUESTLOG_SWAP_QUEST",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogSwapQuest         },
    /*0x194*/ { "CMSG_QUESTLOG_REMOVE_QUEST",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogRemoveQuest       },
    /*0x195*/ { "SMSG_QUESTLOG_FULL",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x196*/ { "SMSG_QUESTUPDATE_FAILED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x197*/ { "SMSG_QUESTUPDATE_FAILEDTIMER",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x198*/ { "SMSG_QUESTUPDATE_COMPLETE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x199*/ { "SMSG_QUESTUPDATE_ADD_KILL",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x19A*/ { "SMSG_QUESTUPDATE_ADD_ITEM_OBSOLETE",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x19B*/ { "CMSG_QUEST_CONFIRM_ACCEPT",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestConfirmAccept        },
    /*0x19C*/ { "SMSG_QUEST_CONFIRM_ACCEPT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x19D*/ { "CMSG_PUSHQUESTTOPARTY",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePushQuestToParty          },
    /*0x19E*/ { "CMSG_LIST_INVENTORY",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListInventoryOpcode       },
    /*0x19F*/ { "SMSG_LIST_INVENTORY",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1A0*/ { "CMSG_SELL_ITEM",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSellItemOpcode            },
    /*0x1A1*/ { "SMSG_SELL_ITEM",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1A2*/ { "CMSG_BUY_ITEM",                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemOpcode             },
    /*0x1A3*/ { "CMSG_BUY_ITEM_IN_SLOT",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemInSlotOpcode       },
    /*0x1A4*/ { "SMSG_BUY_ITEM",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1A5*/ { "SMSG_BUY_FAILED",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1A6*/ { "CMSG_TAXICLEARALLNODES",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1A7*/ { "CMSG_TAXIENABLEALLNODES",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1A8*/ { "CMSG_TAXISHOWNODES",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1A9*/ { "SMSG_SHOWTAXINODES",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1AA*/ { "CMSG_TAXINODE_STATUS_QUERY",                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiNodeStatusQueryOpcode },
    /*0x1AB*/ { "SMSG_TAXINODE_STATUS",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1AC*/ { "CMSG_TAXIQUERYAVAILABLENODES",                 STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiQueryAvailableNodes   },
    /*0x1AD*/ { "CMSG_ACTIVATETAXI",                            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleActivateTaxiOpcode        },
    /*0x1AE*/ { "SMSG_ACTIVATETAXIREPLY",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1AF*/ { "SMSG_NEW_TAXI_PATH",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1B0*/ { "CMSG_TRAINER_LIST",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerListOpcode         },
    /*0x1B1*/ { "SMSG_TRAINER_LIST",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1B2*/ { "CMSG_TRAINER_BUY_SPELL",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerBuySpellOpcode     },
    /*0x1B3*/ { "SMSG_TRAINER_BUY_SUCCEEDED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1B4*/ { "SMSG_TRAINER_BUY_FAILED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1B5*/ { "CMSG_BINDER_ACTIVATE",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBinderActivateOpcode      },
    /*0x1B6*/ { "SMSG_PLAYERBINDERROR",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1B7*/ { "CMSG_BANKER_ACTIVATE",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBankerActivateOpcode      },
    /*0x1B8*/ { "SMSG_SHOW_BANK",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1B9*/ { "CMSG_BUY_BANK_SLOT",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyBankSlotOpcode         },
    /*0x1BA*/ { "SMSG_BUY_BANK_SLOT_RESULT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1BB*/ { "CMSG_PETITION_SHOWLIST",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowListOpcode    },
    /*0x1BC*/ { "SMSG_PETITION_SHOWLIST",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1BD*/ { "CMSG_PETITION_BUY",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionBuyOpcode         },
    /*0x1BE*/ { "CMSG_PETITION_SHOW_SIGNATURES",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowSignOpcode    },
    /*0x1BF*/ { "SMSG_PETITION_SHOW_SIGNATURES",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1C0*/ { "CMSG_PETITION_SIGN",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionSignOpcode        },
    /*0x1C1*/ { "SMSG_PETITION_SIGN_RESULTS",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1C2*/ { "MSG_PETITION_DECLINE",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionDeclineOpcode     },
    /*0x1C3*/ { "CMSG_OFFER_PETITION",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOfferPetitionOpcode       },
    /*0x1C4*/ { "CMSG_TURN_IN_PETITION",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTurnInPetitionOpcode      },
    /*0x1C5*/ { "SMSG_TURN_IN_PETITION_RESULTS",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1C6*/ { "CMSG_PETITION_QUERY",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionQueryOpcode       },
    /*0x1C7*/ { "SMSG_PETITION_QUERY_RESPONSE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1C8*/ { "SMSG_FISH_NOT_HOOKED",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1C9*/ { "SMSG_FISH_ESCAPED",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1CA*/ { "CMSG_BUG",                                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBugOpcode                 },
    /*0x1CB*/ { "SMSG_NOTIFICATION",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1CC*/ { "CMSG_PLAYED_TIME",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayedTime                },
    /*0x1CD*/ { "SMSG_PLAYED_TIME",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1CE*/ { "CMSG_QUERY_TIME",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryTimeOpcode           },
    /*0x1CF*/ { "SMSG_QUERY_TIME_RESPONSE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1D0*/ { "SMSG_LOG_XPGAIN",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1D1*/ { "SMSG_AURACASTLOG",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1D2*/ { "CMSG_RECLAIM_CORPSE",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReclaimCorpseOpcode       },
    /*0x1D3*/ { "CMSG_WRAP_ITEM",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWrapItemOpcode            },
    /*0x1D4*/ { "SMSG_LEVELUP_INFO",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1D5*/ { "MSG_MINIMAP_PING",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMinimapPingOpcode         },
    /*0x1D6*/ { "SMSG_RESISTLOG",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1D7*/ { "SMSG_ENCHANTMENTLOG",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1D8*/ { "CMSG_SET_SKILL_CHEAT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1D9*/ { "SMSG_START_MIRROR_TIMER",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1DA*/ { "SMSG_PAUSE_MIRROR_TIMER",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1DB*/ { "SMSG_STOP_MIRROR_TIMER",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1DC*/ { "CMSG_PING",                                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_EarlyProccess            },
    /*0x1DD*/ { "SMSG_PONG",                                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1DE*/ { "SMSG_CLEAR_COOLDOWN",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1DF*/ { "SMSG_GAMEOBJECT_PAGETEXT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1E0*/ { "CMSG_SETSHEATHED",                             STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetSheathedOpcode         },
    /*0x1E1*/ { "SMSG_COOLDOWN_CHEAT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1E2*/ { "SMSG_SPELL_DELAYED",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1E3*/ { "CMSG_QUEST_POI_QUERY",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPOIQueryOpcode       },
    /*0x1E4*/ { "SMSG_QUEST_POI_QUERY_RESPONSE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1E5*/ { "CMSG_GHOST",                                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1E6*/ { "CMSG_GM_INVIS",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1E7*/ { "SMSG_INVALID_PROMOTION_CODE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1E8*/ { "MSG_GM_BIND_OTHER",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1E9*/ { "MSG_GM_SUMMON",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1EA*/ { "SMSG_ITEM_TIME_UPDATE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1EB*/ { "SMSG_ITEM_ENCHANT_TIME_UPDATE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1EC*/ { "SMSG_AUTH_CHALLENGE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1ED*/ { "CMSG_AUTH_SESSION",                            STATUS_NEVER,    PROCESS_THREADUNSAFE, &WorldSession::Handle_EarlyProccess            },
    /*0x1EE*/ { "SMSG_AUTH_RESPONSE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1EF*/ { "MSG_GM_SHOWLABEL",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1F0*/ { "CMSG_PET_CAST_SPELL",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetCastSpellOpcode        },
    /*0x1F1*/ { "MSG_SAVE_GUILD_EMBLEM",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSaveGuildEmblemOpcode     },
    /*0x1F2*/ { "MSG_TABARDVENDOR_ACTIVATE",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTabardVendorActivateOpcode},
    /*0x1F3*/ { "SMSG_PLAY_SPELL_VISUAL",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1F4*/ { "CMSG_ZONEUPDATE",                              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleZoneUpdateOpcode          },
    /*0x1F5*/ { "SMSG_PARTYKILLLOG",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1F6*/ { "SMSG_COMPRESSED_UPDATE_OBJECT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1F7*/ { "SMSG_PLAY_SPELL_IMPACT",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1F8*/ { "SMSG_EXPLORATION_EXPERIENCE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1F9*/ { "CMSG_GM_SET_SECURITY_GROUP",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1FA*/ { "CMSG_GM_NUKE",                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1FB*/ { "MSG_RANDOM_ROLL",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRandomRollOpcode          },
    /*0x1FC*/ { "SMSG_ENVIRONMENTALDAMAGELOG",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1FD*/ { "CMSG_CHANGEPLAYER_DIFFICULTY",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x1FE*/ { "SMSG_RWHOIS",                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x1FF*/ { "SMSG_LFG_PLAYER_REWARD",                       STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x200*/ { "SMSG_LFG_TELEPORT_DENIED",                     STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x201*/ { "CMSG_UNLEARN_SPELL",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x202*/ { "CMSG_UNLEARN_SKILL",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnlearnSkillOpcode        },
    /*0x203*/ { "SMSG_REMOVED_SPELL",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x204*/ { "CMSG_DECHARGE",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x205*/ { "CMSG_GMTICKET_CREATE",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketCreateOpcode      },
    /*0x206*/ { "SMSG_GMTICKET_CREATE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x207*/ { "CMSG_GMTICKET_UPDATETEXT",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketUpdateTextOpcode  },
    /*0x208*/ { "SMSG_GMTICKET_UPDATETEXT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x209*/ { "SMSG_ACCOUNT_DATA_TIMES",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x20A*/ { "CMSG_REQUEST_ACCOUNT_DATA",                    STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleRequestAccountData        },
    /*0x20B*/ { "CMSG_UPDATE_ACCOUNT_DATA",                     STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleUpdateAccountData},
    /*0x20C*/ { "SMSG_UPDATE_ACCOUNT_DATA",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x20D*/ { "SMSG_CLEAR_FAR_SIGHT_IMMEDIATE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x20E*/ { "SMSG_CHANGEPLAYER_DIFFICULTY_RESULT",          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x20F*/ { "CMSG_GM_TEACH",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x210*/ { "CMSG_GM_CREATE_ITEM_TARGET",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x211*/ { "CMSG_GMTICKET_GETTICKET",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketGetTicketOpcode   },
    /*0x212*/ { "SMSG_GMTICKET_GETTICKET",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x213*/ { "CMSG_UNLEARN_TALENTS",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x214*/ { "SMSG_INSTANCE_ENCOUNTER",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x215*/ { "SMSG_GAMEOBJECT_DESPAWN_ANIM",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x216*/ { "MSG_CORPSE_QUERY",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseQueryOpcode         },
    /*0x217*/ { "CMSG_GMTICKET_DELETETICKET",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketDeleteTicketOpcode},
    /*0x218*/ { "SMSG_GMTICKET_DELETETICKET",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x219*/ { "SMSG_CHAT_WRONG_FACTION",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x21A*/ { "CMSG_GMTICKET_SYSTEMSTATUS",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketSystemStatusOpcode},
    /*0x21B*/ { "SMSG_GMTICKET_SYSTEMSTATUS",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x21C*/ { "CMSG_SPIRIT_HEALER_ACTIVATE",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSpiritHealerActivateOpcode},
    /*0x21D*/ { "CMSG_SET_STAT_CHEAT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x21E*/ { "SMSG_QUEST_FORCE_REMOVED",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x21F*/ { "CMSG_SKILL_BUY_STEP",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x220*/ { "CMSG_SKILL_BUY_RANK",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x221*/ { "CMSG_XP_CHEAT",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x222*/ { "SMSG_SPIRIT_HEALER_CONFIRM",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x223*/ { "CMSG_CHARACTER_POINT_CHEAT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x224*/ { "SMSG_GOSSIP_POI",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x225*/ { "CMSG_CHAT_IGNORED",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChatIgnoredOpcode         },
    /*0x226*/ { "CMSG_GM_VISION",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x227*/ { "CMSG_SERVER_COMMAND",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x228*/ { "CMSG_GM_SILENCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x229*/ { "CMSG_GM_REVEALTO",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x22A*/ { "CMSG_GM_RESURRECT",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x22B*/ { "CMSG_GM_SUMMONMOB",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x22C*/ { "CMSG_GM_MOVECORPSE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x22D*/ { "CMSG_GM_FREEZE",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x22E*/ { "CMSG_GM_UBERINVIS",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x22F*/ { "CMSG_GM_REQUEST_PLAYER_INFO",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x230*/ { "SMSG_GM_PLAYER_INFO",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x231*/ { "CMSG_GUILD_RANK",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRankOpcode           },
    /*0x232*/ { "CMSG_GUILD_ADD_RANK",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAddRankOpcode        },
    /*0x233*/ { "CMSG_GUILD_DEL_RANK",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDelRankOpcode        },
    /*0x234*/ { "CMSG_GUILD_SET_PUBLIC_NOTE",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetPublicNoteOpcode  },
    /*0x235*/ { "CMSG_GUILD_SET_OFFICER_NOTE",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetOfficerNoteOpcode },
    /*0x236*/ { "SMSG_LOGIN_VERIFY_WORLD",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x237*/ { "CMSG_CLEAR_EXPLORATION",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x238*/ { "CMSG_SEND_MAIL",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSendMail                  },
    /*0x239*/ { "SMSG_SEND_MAIL_RESULT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x23A*/ { "CMSG_GET_MAIL_LIST",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetMailList               },
    /*0x23B*/ { "SMSG_MAIL_LIST_RESULT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x23C*/ { "CMSG_BATTLEFIELD_LIST",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldListOpcode     },
    /*0x23D*/ { "SMSG_BATTLEFIELD_LIST",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x23E*/ { "CMSG_BATTLEFIELD_JOIN",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x23F*/ { "SMSG_FORCE_SET_VEHICLE_REC_ID",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x240*/ { "CMSG_SET_VEHICLE_REC_ID_ACK",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x241*/ { "CMSG_TAXICLEARNODE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x242*/ { "CMSG_TAXIENABLENODE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x243*/ { "CMSG_ITEM_TEXT_QUERY",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemTextQuery             },
    /*0x244*/ { "SMSG_ITEM_TEXT_QUERY_RESPONSE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x245*/ { "CMSG_MAIL_TAKE_MONEY",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeMoney             },
    /*0x246*/ { "CMSG_MAIL_TAKE_ITEM",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeItem              },
    /*0x247*/ { "CMSG_MAIL_MARK_AS_READ",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailMarkAsRead            },
    /*0x248*/ { "CMSG_MAIL_RETURN_TO_SENDER",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailReturnToSender        },
    /*0x249*/ { "CMSG_MAIL_DELETE",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailDelete                },
    /*0x24A*/ { "CMSG_MAIL_CREATE_TEXT_ITEM",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailCreateTextItem        },
    /*0x24B*/ { "SMSG_SPELLLOGMISS",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x24C*/ { "SMSG_SPELLLOGEXECUTE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x24D*/ { "SMSG_DEBUGAURAPROC",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x24E*/ { "SMSG_PERIODICAURALOG",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x24F*/ { "SMSG_SPELLDAMAGESHIELD",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x250*/ { "SMSG_SPELLNONMELEEDAMAGELOG",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x251*/ { "CMSG_LEARN_TALENT",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnTalentOpcode         },
    /*0x252*/ { "SMSG_RESURRECT_FAILED",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x253*/ { "CMSG_TOGGLE_PVP",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTogglePvP                 },
    /*0x254*/ { "SMSG_ZONE_UNDER_ATTACK",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x255*/ { "MSG_AUCTION_HELLO",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionHelloOpcode        },
    /*0x256*/ { "CMSG_AUCTION_SELL_ITEM",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionSellItem           },
    /*0x257*/ { "CMSG_AUCTION_REMOVE_ITEM",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionRemoveItem         },
    /*0x258*/ { "CMSG_AUCTION_LIST_ITEMS",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListItems          },
    /*0x259*/ { "CMSG_AUCTION_LIST_OWNER_ITEMS",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListOwnerItems     },
    /*0x25A*/ { "CMSG_AUCTION_PLACE_BID",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionPlaceBid           },
    /*0x25B*/ { "SMSG_AUCTION_COMMAND_RESULT",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x25C*/ { "SMSG_AUCTION_LIST_RESULT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x25D*/ { "SMSG_AUCTION_OWNER_LIST_RESULT",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x25E*/ { "SMSG_AUCTION_BIDDER_NOTIFICATION",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x25F*/ { "SMSG_AUCTION_OWNER_NOTIFICATION",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x260*/ { "SMSG_PROCRESIST",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x261*/ { "SMSG_COMBAT_EVENT_FAILED",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x262*/ { "SMSG_DISPEL_FAILED",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x263*/ { "SMSG_SPELLORDAMAGE_IMMUNE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x264*/ { "CMSG_AUCTION_LIST_BIDDER_ITEMS",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListBidderItems    },
    /*0x265*/ { "SMSG_AUCTION_BIDDER_LIST_RESULT",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x266*/ { "SMSG_SET_FLAT_SPELL_MODIFIER",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x267*/ { "SMSG_SET_PCT_SPELL_MODIFIER",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x268*/ { "CMSG_SET_AMMO",                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetAmmoOpcode             },
    /*0x269*/ { "SMSG_CORPSE_RECLAIM_DELAY",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x26A*/ { "CMSG_SET_ACTIVE_MOVER",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveMoverOpcode      },
    /*0x26B*/ { "CMSG_PET_CANCEL_AURA",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetCancelAuraOpcode       },
    /*0x26C*/ { "CMSG_PLAYER_AI_CHEAT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x26D*/ { "CMSG_CANCEL_AUTO_REPEAT_SPELL",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelAutoRepeatSpellOpcode},
    /*0x26E*/ { "MSG_GM_ACCOUNT_ONLINE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x26F*/ { "MSG_LIST_STABLED_PETS",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListStabledPetsOpcode     },
    /*0x270*/ { "CMSG_STABLE_PET",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStablePet                 },
    /*0x271*/ { "CMSG_UNSTABLE_PET",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnstablePet               },
    /*0x272*/ { "CMSG_BUY_STABLE_SLOT",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyStableSlot             },
    /*0x273*/ { "SMSG_STABLE_RESULT",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x274*/ { "CMSG_STABLE_REVIVE_PET",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableRevivePet           },
    /*0x275*/ { "CMSG_STABLE_SWAP_PET",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableSwapPet             },
    /*0x276*/ { "MSG_QUEST_PUSH_RESULT",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPushResult           },
    /*0x277*/ { "SMSG_PLAY_MUSIC",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x278*/ { "SMSG_PLAY_OBJECT_SOUND",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x279*/ { "CMSG_REQUEST_PET_INFO",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPetInfoOpcode      },
    /*0x27A*/ { "CMSG_FAR_SIGHT",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleFarSightOpcode            },
    /*0x27B*/ { "SMSG_SPELLDISPELLOG",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x27C*/ { "SMSG_DAMAGE_CALC_LOG",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x27D*/ { "CMSG_ENABLE_DAMAGE_LOG",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x27E*/ { "CMSG_GROUP_CHANGE_SUB_GROUP",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupChangeSubGroupOpcode },
    /*0x27F*/ { "CMSG_REQUEST_PARTY_MEMBER_STATS",              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPartyMemberStatsOpcode},
    /*0x280*/ { "CMSG_GROUP_SWAP_SUB_GROUP",                    STATUS_UNHANDLED,PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x281*/ { "CMSG_RESET_FACTION_CHEAT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x282*/ { "CMSG_AUTOSTORE_BANK_ITEM",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBankItemOpcode   },
    /*0x283*/ { "CMSG_AUTOBANK_ITEM",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoBankItemOpcode        },
    /*0x284*/ { "MSG_QUERY_NEXT_MAIL_TIME",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryNextMailTime         },
    /*0x285*/ { "SMSG_RECEIVED_MAIL",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x286*/ { "SMSG_RAID_GROUP_ONLY",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x287*/ { "CMSG_SET_DURABILITY_CHEAT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x288*/ { "CMSG_SET_PVP_RANK_CHEAT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x289*/ { "CMSG_ADD_PVP_MEDAL_CHEAT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x28A*/ { "CMSG_DEL_PVP_MEDAL_CHEAT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x28B*/ { "CMSG_SET_PVP_TITLE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x28C*/ { "SMSG_PVP_CREDIT",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x28D*/ { "SMSG_AUCTION_REMOVED_NOTIFICATION",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x28E*/ { "CMSG_GROUP_RAID_CONVERT",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupRaidConvertOpcode    },
    /*0x28F*/ { "CMSG_GROUP_ASSISTANT_LEADER",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAssistantLeaderOpcode},
    /*0x290*/ { "CMSG_BUYBACK_ITEM",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuybackItem               },
    /*0x291*/ { "SMSG_SERVER_MESSAGE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x292*/ { "CMSG_SET_SAVED_INSTANCE_EXTEND",               STATUS_UNHANDLED,PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x293*/ { "SMSG_LFG_OFFER_CONTINUE",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x294*/ { "CMSG_TEST_DROP_RATE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x295*/ { "SMSG_TEST_DROP_RATE_RESULT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x296*/ { "CMSG_LFG_GET_STATUS",                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgGetStatus              },
    /*0x297*/ { "SMSG_SHOW_MAILBOX",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x298*/ { "SMSG_RESET_RANGED_COMBAT_TIMER",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x299*/ { "SMSG_CHAT_NOT_IN_PARTY",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x29A*/ { "CMSG_GMTICKETSYSTEM_TOGGLE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x29B*/ { "CMSG_CANCEL_GROWTH_AURA",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelGrowthAuraOpcode    },
    /*0x29C*/ { "SMSG_CANCEL_AUTO_REPEAT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x29D*/ { "SMSG_STANDSTATE_UPDATE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x29E*/ { "SMSG_LOOT_ALL_PASSED",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x29F*/ { "SMSG_LOOT_ROLL_WON",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A0*/ { "CMSG_LOOT_ROLL",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootRoll                  },
    /*0x2A1*/ { "SMSG_LOOT_START_ROLL",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A2*/ { "SMSG_LOOT_ROLL",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A3*/ { "CMSG_LOOT_MASTER_GIVE",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMasterGiveOpcode      },
    /*0x2A4*/ { "SMSG_LOOT_MASTER_LIST",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A5*/ { "SMSG_SET_FORCED_REACTIONS",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A6*/ { "SMSG_SPELL_FAILED_OTHER",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A7*/ { "SMSG_GAMEOBJECT_RESET_STATE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2A8*/ { "CMSG_REPAIR_ITEM",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepairItemOpcode          },
    /*0x2A9*/ { "SMSG_CHAT_PLAYER_NOT_FOUND",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2AA*/ { "MSG_TALENT_WIPE_CONFIRM",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTalentWipeConfirmOpcode   },
    /*0x2AB*/ { "SMSG_SUMMON_REQUEST",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2AC*/ { "CMSG_SUMMON_RESPONSE",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSummonResponseOpcode      },
    /*0x2AD*/ { "MSG_DEV_SHOWLABEL",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2AE*/ { "SMSG_MONSTER_MOVE_TRANSPORT",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2AF*/ { "SMSG_PET_BROKEN",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2B0*/ { "MSG_MOVE_FEATHER_FALL",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2B1*/ { "MSG_MOVE_WATER_WALK",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2B2*/ { "CMSG_SERVER_BROADCAST",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2B3*/ { "CMSG_SELF_RES",                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSelfResOpcode             },
    /*0x2B4*/ { "SMSG_FEIGN_DEATH_RESISTED",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2B5*/ { "CMSG_RUN_SCRIPT",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2B6*/ { "SMSG_SCRIPT_MESSAGE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2B7*/ { "SMSG_DUEL_COUNTDOWN",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2B8*/ { "SMSG_AREA_TRIGGER_MESSAGE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2B9*/ { "CMSG_SHOWING_HELM",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingHelmOpcode         },
    /*0x2BA*/ { "CMSG_SHOWING_CLOAK",                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingCloakOpcode        },
    /*0x2BB*/ { "SMSG_ROLE_CHOSEN",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2BC*/ { "SMSG_PLAYER_SKINNED",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2BD*/ { "SMSG_DURABILITY_DAMAGE_DEATH",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2BE*/ { "CMSG_SET_EXPLORATION",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2BF*/ { "CMSG_SET_ACTIONBAR_TOGGLES",                   STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionBarTogglesOpcode },
    /*0x2C0*/ { "UMSG_DELETE_GUILD_CHARTER",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2C1*/ { "MSG_PETITION_RENAME",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionRenameOpcode      },
    /*0x2C2*/ { "SMSG_INIT_WORLD_STATES",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2C3*/ { "SMSG_UPDATE_WORLD_STATE",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2C4*/ { "CMSG_ITEM_NAME_QUERY",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemNameQueryOpcode       },
    /*0x2C5*/ { "SMSG_ITEM_NAME_QUERY_RESPONSE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2C6*/ { "SMSG_PET_ACTION_FEEDBACK",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2C7*/ { "CMSG_CHAR_RENAME",                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharRenameOpcode          },
    /*0x2C8*/ { "SMSG_CHAR_RENAME",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2C9*/ { "CMSG_MOVE_SPLINE_DONE",                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSplineDoneOpcode      },
    /*0x2CA*/ { "CMSG_MOVE_FALL_RESET",                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x2CB*/ { "SMSG_INSTANCE_SAVE_CREATED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2CC*/ { "SMSG_RAID_INSTANCE_INFO",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2CD*/ { "CMSG_REQUEST_RAID_INFO",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestRaidInfoOpcode     },
    /*0x2CE*/ { "CMSG_MOVE_TIME_SKIPPED",                       STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleMoveTimeSkippedOpcode     },
    /*0x2CF*/ { "CMSG_MOVE_FEATHER_FALL_ACK",                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleFeatherFallAck            },
    /*0x2D0*/ { "CMSG_MOVE_WATER_WALK_ACK",                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveWaterWalkAck          },
    /*0x2D1*/ { "CMSG_MOVE_NOT_ACTIVE_MOVER",                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveNotActiveMoverOpcode  },
    /*0x2D2*/ { "SMSG_PLAY_SOUND",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2D3*/ { "CMSG_BATTLEFIELD_STATUS",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldStatusOpcode   },
    /*0x2D4*/ { "SMSG_BATTLEFIELD_STATUS",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2D5*/ { "CMSG_BATTLEFIELD_PORT",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattleFieldPortOpcode     },
    /*0x2D6*/ { "MSG_INSPECT_HONOR_STATS",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectHonorStatsOpcode   },
    /*0x2D7*/ { "CMSG_BATTLEMASTER_HELLO",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterHelloOpcode   },
    /*0x2D8*/ { "CMSG_MOVE_START_SWIM_CHEAT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2D9*/ { "CMSG_MOVE_STOP_SWIM_CHEAT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2DA*/ { "SMSG_FORCE_WALK_SPEED_CHANGE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2DB*/ { "CMSG_FORCE_WALK_SPEED_CHANGE_ACK",             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x2DC*/ { "SMSG_FORCE_SWIM_BACK_SPEED_CHANGE",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2DD*/ { "CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK",        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x2DE*/ { "SMSG_FORCE_TURN_RATE_CHANGE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2DF*/ { "CMSG_FORCE_TURN_RATE_CHANGE_ACK",              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x2E0*/ { "MSG_PVP_LOG_DATA",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePVPLogDataOpcode          },
    /*0x2E1*/ { "CMSG_LEAVE_BATTLEFIELD",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveBattlefieldOpcode    },
    /*0x2E2*/ { "CMSG_AREA_SPIRIT_HEALER_QUERY",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaSpiritHealerQueryOpcode},
    /*0x2E3*/ { "CMSG_AREA_SPIRIT_HEALER_QUEUE",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaSpiritHealerQueueOpcode},
    /*0x2E4*/ { "SMSG_AREA_SPIRIT_HEALER_TIME",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2E5*/ { "CMSG_GM_UNTEACH",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2E6*/ { "SMSG_WARDEN_DATA",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2E7*/ { "CMSG_WARDEN_DATA",                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleWardenDataOpcode          },
    /*0x2E8*/ { "SMSG_GROUP_JOINED_BATTLEGROUND",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2E9*/ { "MSG_BATTLEGROUND_PLAYER_POSITIONS",            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattleGroundPlayerPositionsOpcode},
    /*0x2EA*/ { "CMSG_PET_STOP_ATTACK",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetStopAttack             },
    /*0x2EB*/ { "SMSG_BINDER_CONFIRM",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2EC*/ { "SMSG_BATTLEGROUND_PLAYER_JOINED",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2ED*/ { "SMSG_BATTLEGROUND_PLAYER_LEFT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2EE*/ { "CMSG_BATTLEMASTER_JOIN",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinOpcode    },
    /*0x2EF*/ { "SMSG_ADDON_INFO",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F0*/ { "CMSG_PET_UNLEARN",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetUnlearnOpcode          },
    /*0x2F1*/ { "SMSG_PET_UNLEARN_CONFIRM",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F2*/ { "SMSG_PARTY_MEMBER_STATS_FULL",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F3*/ { "CMSG_PET_SPELL_AUTOCAST",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSpellAutocastOpcode    },
    /*0x2F4*/ { "SMSG_WEATHER",                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F5*/ { "SMSG_PLAY_TIME_WARNING",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F6*/ { "SMSG_MINIGAME_SETUP",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F7*/ { "SMSG_MINIGAME_STATE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2F8*/ { "CMSG_MINIGAME_MOVE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x2F9*/ { "SMSG_MINIGAME_MOVE_FAILED",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2FA*/ { "SMSG_RAID_INSTANCE_MESSAGE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2FB*/ { "SMSG_COMPRESSED_MOVES",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2FC*/ { "CMSG_GUILD_INFO_TEXT",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildChangeInfoTextOpcode },
    /*0x2FD*/ { "SMSG_CHAT_RESTRICTED",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2FE*/ { "SMSG_SPLINE_SET_RUN_SPEED",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x2FF*/ { "SMSG_SPLINE_SET_RUN_BACK_SPEED",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x300*/ { "SMSG_SPLINE_SET_SWIM_SPEED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x301*/ { "SMSG_SPLINE_SET_WALK_SPEED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x302*/ { "SMSG_SPLINE_SET_SWIM_BACK_SPEED",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x303*/ { "SMSG_SPLINE_SET_TURN_RATE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x304*/ { "SMSG_SPLINE_MOVE_UNROOT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x305*/ { "SMSG_SPLINE_MOVE_FEATHER_FALL",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x306*/ { "SMSG_SPLINE_MOVE_NORMAL_FALL",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x307*/ { "SMSG_SPLINE_MOVE_SET_HOVER",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x308*/ { "SMSG_SPLINE_MOVE_UNSET_HOVER",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x309*/ { "SMSG_SPLINE_MOVE_WATER_WALK",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x30A*/ { "SMSG_SPLINE_MOVE_LAND_WALK",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x30B*/ { "SMSG_SPLINE_MOVE_START_SWIM",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x30C*/ { "SMSG_SPLINE_MOVE_STOP_SWIM",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x30D*/ { "SMSG_SPLINE_MOVE_SET_RUN_MODE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x30E*/ { "SMSG_SPLINE_MOVE_SET_WALK_MODE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x30F*/ { "CMSG_GM_NUKE_ACCOUNT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x310*/ { "MSG_GM_DESTROY_CORPSE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x311*/ { "CMSG_GM_DESTROY_ONLINE_CORPSE",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x312*/ { "CMSG_ACTIVATETAXIEXPRESS",                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleActivateTaxiExpressOpcode },
    /*0x313*/ { "SMSG_SET_FACTION_ATWAR",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x314*/ { "SMSG_GAMETIMEBIAS_SET",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x315*/ { "CMSG_DEBUG_ACTIONS_START",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x316*/ { "CMSG_DEBUG_ACTIONS_STOP",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x317*/ { "CMSG_SET_FACTION_INACTIVE",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionInactiveOpcode  },
    /*0x318*/ { "CMSG_SET_WATCHED_FACTION",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetWatchedFactionOpcode   },
    /*0x319*/ { "MSG_MOVE_TIME_SKIPPED",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x31A*/ { "SMSG_SPLINE_MOVE_ROOT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x31B*/ { "CMSG_SET_EXPLORATION_ALL",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x31C*/ { "SMSG_INVALIDATE_PLAYER",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x31D*/ { "CMSG_RESET_INSTANCES",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleResetInstancesOpcode      },
    /*0x31E*/ { "SMSG_INSTANCE_RESET",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x31F*/ { "SMSG_INSTANCE_RESET_FAILED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x320*/ { "SMSG_UPDATE_LAST_INSTANCE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x321*/ { "MSG_RAID_TARGET_UPDATE",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidTargetUpdateOpcode    },
    /*0x322*/ { "MSG_RAID_READY_CHECK",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckOpcode      },
    /*0x323*/ { "CMSG_LUA_USAGE",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x324*/ { "SMSG_PET_ACTION_SOUND",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x325*/ { "SMSG_PET_DISMISS_SOUND",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x326*/ { "SMSG_GHOSTEE_GONE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x327*/ { "CMSG_GM_UPDATE_TICKET_STATUS",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x328*/ { "SMSG_GM_TICKET_STATUS_UPDATE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x329*/ { "MSG_SET_DUNGEON_DIFFICULTY",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetDungeonDifficultyOpcode},
    /*0x32A*/ { "CMSG_GMSURVEY_SUBMIT",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMSurveySubmitOpcode      },
    /*0x32B*/ { "SMSG_UPDATE_INSTANCE_OWNERSHIP",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x32C*/ { "CMSG_IGNORE_KNOCKBACK_CHEAT",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x32D*/ { "SMSG_CHAT_PLAYER_AMBIGUOUS",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x32E*/ { "MSG_DELAY_GHOST_TELEPORT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x32F*/ { "SMSG_SPELLINSTAKILLLOG",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x330*/ { "SMSG_SPELL_UPDATE_CHAIN_TARGETS",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x331*/ { "CMSG_CHAT_FILTERED",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x332*/ { "SMSG_EXPECTED_SPAM_RECORDS",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x333*/ { "SMSG_SPELLSTEALLOG",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x334*/ { "CMSG_LOTTERY_QUERY_OBSOLETE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x335*/ { "SMSG_LOTTERY_QUERY_RESULT_OBSOLETE",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x336*/ { "CMSG_BUY_LOTTERY_TICKET_OBSOLETE",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x337*/ { "SMSG_LOTTERY_RESULT_OBSOLETE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x338*/ { "SMSG_CHARACTER_PROFILE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x339*/ { "SMSG_CHARACTER_PROFILE_REALM_CONNECTED",       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x33A*/ { "SMSG_DEFENSE_MESSAGE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x33B*/ { "SMSG_INSTANCE_DIFFICULTY",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x33C*/ { "MSG_GM_RESETINSTANCELIMIT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x33D*/ { "SMSG_MOTD",                                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x33E*/ { "SMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY",STATUS_NEVER,PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x33F*/ { "SMSG_MOVE_UNSET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY",STATUS_NEVER,PROCESS_INPLACE,    &WorldSession::Handle_ServerSide               },
    /*0x340*/ { "CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK",STATUS_NEVER,PROCESS_INPLACE,  &WorldSession::Handle_NULL                     },
    /*0x341*/ { "MSG_MOVE_START_SWIM_CHEAT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x342*/ { "MSG_MOVE_STOP_SWIM_CHEAT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x343*/ { "SMSG_MOVE_SET_CAN_FLY",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x344*/ { "SMSG_MOVE_UNSET_CAN_FLY",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x345*/ { "CMSG_MOVE_SET_CAN_FLY_ACK",                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSetCanFlyAckOpcode    },
    /*0x346*/ { "CMSG_MOVE_SET_FLY",                            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x347*/ { "CMSG_SOCKET_GEMS",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSocketOpcode              },
    /*0x348*/ { "CMSG_ARENA_TEAM_CREATE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x349*/ { "SMSG_ARENA_TEAM_COMMAND_RESULT",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x34A*/ { "MSG_MOVE_UPDATE_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY",STATUS_NEVER,PROCESS_INPLACE,    &WorldSession::Handle_NULL                     },
    /*0x34B*/ { "CMSG_ARENA_TEAM_QUERY",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamQueryOpcode      },
    /*0x34C*/ { "SMSG_ARENA_TEAM_QUERY_RESPONSE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x34D*/ { "CMSG_ARENA_TEAM_ROSTER",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRosterOpcode     },
    /*0x34E*/ { "SMSG_ARENA_TEAM_ROSTER",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x34F*/ { "CMSG_ARENA_TEAM_INVITE",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamInviteOpcode     },
    /*0x350*/ { "SMSG_ARENA_TEAM_INVITE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x351*/ { "CMSG_ARENA_TEAM_ACCEPT",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamAcceptOpcode     },
    /*0x352*/ { "CMSG_ARENA_TEAM_DECLINE",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDeclineOpcode    },
    /*0x353*/ { "CMSG_ARENA_TEAM_LEAVE",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaveOpcode      },
    /*0x354*/ { "CMSG_ARENA_TEAM_REMOVE",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRemoveOpcode     },
    /*0x355*/ { "CMSG_ARENA_TEAM_DISBAND",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDisbandOpcode    },
    /*0x356*/ { "CMSG_ARENA_TEAM_LEADER",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaderOpcode     },
    /*0x357*/ { "SMSG_ARENA_TEAM_EVENT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x358*/ { "CMSG_BATTLEMASTER_JOIN_ARENA",                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinArena     },
    /*0x359*/ { "MSG_MOVE_START_ASCEND",                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x35A*/ { "MSG_MOVE_STOP_ASCEND",                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x35B*/ { "SMSG_ARENA_TEAM_STATS",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x35C*/ { "CMSG_LFG_JOIN",                                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgJoinOpcode             },
    /*0x35D*/ { "CMSG_LFG_LEAVE",                               STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgLeaveOpcode            },
    /*0x35E*/ { "CMSG_LFG_SEARCH_JOIN",                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfrSearchOpcode           },
    /*0x35F*/ { "CMSG_LFG_SEARCH_LEAVE",                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfrLeaveOpcode            },
    /*0x360*/ { "SMSG_LFG_SEARCH_RESULTS",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x361*/ { "SMSG_LFG_PROPOSAL_UPDATE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x362*/ { "CMSG_LFG_PROPOSAL_RESPONSE",                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgProposalResultOpcode   },
    /*0x363*/ { "SMSG_LFG_ROLE_CHECK_UPDATE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x364*/ { "SMSG_LFG_JOIN_RESULT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x365*/ { "SMSG_LFG_QUEUE_STATUS",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x366*/ { "CMSG_SET_LFG_COMMENT",                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleSetLfgCommentOpcode       },
    /*0x367*/ { "SMSG_LFG_UPDATE_PLAYER",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x368*/ { "SMSG_LFG_UPDATE_PARTY",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x369*/ { "SMSG_LFG_UPDATE_SEARCH",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x36A*/ { "CMSG_LFG_SET_ROLES",                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgSetRolesOpcode         },
    /*0x36B*/ { "CMSG_LFG_SET_NEEDS",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x36C*/ { "CMSG_LFG_BOOT_PLAYER_VOTE",                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgSetBootVoteOpcode      },
    /*0x36D*/ { "SMSG_LFG_BOOT_PLAYER",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x36E*/ { "CMSG_LFG_GET_PLAYER_INFO",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgPlayerLockInfoRequestOpcode},
    /*0x36F*/ { "SMSG_LFG_PLAYER_INFO",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x370*/ { "CMSG_LFG_TELEPORT",                            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgTeleportOpcode         },
    /*0x371*/ { "CMSG_LFG_GET_PARTY_INFO",                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleLfgPartyLockInfoRequestOpcode},
    /*0x372*/ { "SMSG_LFG_PARTY_INFO",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x373*/ { "SMSG_TITLE_EARNED",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x374*/ { "CMSG_SET_TITLE",                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTitleOpcode            },
    /*0x375*/ { "CMSG_CANCEL_MOUNT_AURA",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelMountAuraOpcode     },
    /*0x376*/ { "SMSG_ARENA_ERROR",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x377*/ { "MSG_INSPECT_ARENA_TEAMS",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectArenaTeamsOpcode   },
    /*0x378*/ { "SMSG_DEATH_RELEASE_LOC",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x379*/ { "CMSG_CANCEL_TEMP_ENCHANTMENT",                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTempEnchantmentOpcode},
    /*0x37A*/ { "SMSG_FORCED_DEATH_UPDATE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x37B*/ { "CMSG_CHEAT_SET_HONOR_CURRENCY",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x37C*/ { "CMSG_CHEAT_SET_ARENA_CURRENCY",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x37D*/ { "MSG_MOVE_SET_FLIGHT_SPEED_CHEAT",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x37E*/ { "MSG_MOVE_SET_FLIGHT_SPEED",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x37F*/ { "MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT",         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x380*/ { "MSG_MOVE_SET_FLIGHT_BACK_SPEED",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x381*/ { "SMSG_FORCE_FLIGHT_SPEED_CHANGE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x382*/ { "CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK",           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x383*/ { "SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE",          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x384*/ { "CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK",      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes},
    /*0x385*/ { "SMSG_SPLINE_SET_FLIGHT_SPEED",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x386*/ { "SMSG_SPLINE_SET_FLIGHT_BACK_SPEED",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x387*/ { "CMSG_MAELSTROM_INVALIDATE_CACHE",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x388*/ { "SMSG_FLIGHT_SPLINE_SYNC",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x389*/ { "CMSG_SET_TAXI_BENCHMARK_MODE",                 STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetTaxiBenchmarkOpcode    },
    /*0x38A*/ { "SMSG_JOINED_BATTLEGROUND_QUEUE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x38B*/ { "SMSG_REALM_SPLIT",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x38C*/ { "CMSG_REALM_SPLIT",                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleRealmSplitOpcode          },
    /*0x38D*/ { "CMSG_MOVE_CHNG_TRANSPORT",                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x38E*/ { "MSG_PARTY_ASSIGNMENT",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePartyAssignmentOpcode     },
    /*0x38F*/ { "SMSG_OFFER_PETITION_ERROR",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x390*/ { "SMSG_TIME_SYNC_REQ",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x391*/ { "CMSG_TIME_SYNC_RESP",                          STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleTimeSyncResp              },
    /*0x392*/ { "CMSG_SEND_LOCAL_EVENT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x393*/ { "CMSG_SEND_GENERAL_TRIGGER",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x394*/ { "CMSG_SEND_COMBAT_TRIGGER",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x395*/ { "CMSG_MAELSTROM_GM_SENT_MAIL",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x396*/ { "SMSG_RESET_FAILED_NOTIFY",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x397*/ { "SMSG_REAL_GROUP_UPDATE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x398*/ { "SMSG_LFG_DISABLED",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x399*/ { "CMSG_ACTIVE_PVP_CHEAT",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x39A*/ { "CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x39B*/ { "SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE",    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x39C*/ { "SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE_WRITE_FILE",STATUS_NEVER,PROCESS_INPLACE,      &WorldSession::Handle_ServerSide            },
    /*0x39D*/ { "SMSG_UPDATE_COMBO_POINTS",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x39E*/ { "SMSG_VOICE_SESSION_ROSTER_UPDATE",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x39F*/ { "SMSG_VOICE_SESSION_LEAVE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A0*/ { "SMSG_VOICE_SESSION_ADJUST_PRIORITY",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A1*/ { "CMSG_VOICE_SET_TALKER_MUTED_REQUEST",          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3A2*/ { "SMSG_VOICE_SET_TALKER_MUTED",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A3*/ { "SMSG_INIT_EXTRA_AURA_INFO_OBSOLETE",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A4*/ { "SMSG_SET_EXTRA_AURA_INFO_OBSOLETE",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A5*/ { "SMSG_SET_EXTRA_AURA_INFO_NEED_UPDATE_OBSOLETE",STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A6*/ { "SMSG_CLEAR_EXTRA_AURA_INFO_OBSOLETE",          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3A7*/ { "MSG_MOVE_START_DESCEND",                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           },
    /*0x3A8*/ { "CMSG_IGNORE_REQUIREMENTS_CHEAT",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3A9*/ { "SMSG_IGNORE_REQUIREMENTS_CHEAT",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3AA*/ { "SMSG_SPELL_CHANCE_PROC_LOG",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3AB*/ { "CMSG_MOVE_SET_RUN_SPEED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3AC*/ { "SMSG_DISMOUNT",                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3AD*/ { "MSG_MOVE_UPDATE_CAN_FLY",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3AE*/ { "MSG_RAID_READY_CHECK_CONFIRM",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3AF*/ { "CMSG_VOICE_SESSION_ENABLE",                    STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleVoiceSessionEnableOpcode  },
    /*0x3B0*/ { "SMSG_VOICE_SESSION_ENABLE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3B1*/ { "SMSG_VOICE_PARENTAL_CONTROLS",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3B2*/ { "CMSG_GM_WHISPER",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3B3*/ { "SMSG_GM_MESSAGECHAT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3B4*/ { "MSG_GM_GEARRATING",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3B5*/ { "CMSG_COMMENTATOR_ENABLE",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3B6*/ { "SMSG_COMMENTATOR_STATE_CHANGED",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3B7*/ { "CMSG_COMMENTATOR_GET_MAP_INFO",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3B8*/ { "SMSG_COMMENTATOR_MAP_INFO",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3B9*/ { "CMSG_COMMENTATOR_GET_PLAYER_INFO",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3BA*/ { "SMSG_COMMENTATOR_GET_PLAYER_INFO",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3BB*/ { "SMSG_COMMENTATOR_PLAYER_INFO",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3BC*/ { "CMSG_COMMENTATOR_ENTER_INSTANCE",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3BD*/ { "CMSG_COMMENTATOR_EXIT_INSTANCE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3BE*/ { "CMSG_COMMENTATOR_INSTANCE_COMMAND",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3BF*/ { "SMSG_CLEAR_TARGET",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3C0*/ { "CMSG_BOT_DETECTED",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3C1*/ { "SMSG_CROSSED_INEBRIATION_THRESHOLD",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3C2*/ { "CMSG_CHEAT_PLAYER_LOGIN",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3C3*/ { "CMSG_CHEAT_PLAYER_LOOKUP",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3C4*/ { "SMSG_CHEAT_PLAYER_LOOKUP",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3C5*/ { "SMSG_KICK_REASON",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3C6*/ { "MSG_RAID_READY_CHECK_FINISHED",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckFinishedOpcode},
    /*0x3C7*/ { "CMSG_COMPLAIN",                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleComplainOpcode            },
    /*0x3C8*/ { "SMSG_COMPLAIN_RESULT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3C9*/ { "SMSG_FEATURE_SYSTEM_STATUS",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3CA*/ { "CMSG_GM_SHOW_COMPLAINTS",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3CB*/ { "CMSG_GM_UNSQUELCH",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3CC*/ { "CMSG_CHANNEL_SILENCE_VOICE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3CD*/ { "CMSG_CHANNEL_SILENCE_ALL",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3CE*/ { "CMSG_CHANNEL_UNSILENCE_VOICE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3CF*/ { "CMSG_CHANNEL_UNSILENCE_ALL",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3D0*/ { "CMSG_TARGET_CAST",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3D1*/ { "CMSG_TARGET_SCRIPT_CAST",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3D2*/ { "CMSG_CHANNEL_DISPLAY_LIST",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelDisplayListQueryOpcode},
    /*0x3D3*/ { "CMSG_SET_ACTIVE_VOICE_CHANNEL",                STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveVoiceChannel     },
    /*0x3D4*/ { "CMSG_GET_CHANNEL_MEMBER_COUNT",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetChannelMemberCountOpcode},
    /*0x3D5*/ { "SMSG_CHANNEL_MEMBER_COUNT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3D6*/ { "CMSG_CHANNEL_VOICE_ON",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelVoiceOnOpcode      },
    /*0x3D7*/ { "CMSG_CHANNEL_VOICE_OFF",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3D8*/ { "CMSG_DEBUG_LIST_TARGETS",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3D9*/ { "SMSG_DEBUG_LIST_TARGETS",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3DA*/ { "SMSG_AVAILABLE_VOICE_CHANNEL",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3DB*/ { "CMSG_ADD_VOICE_IGNORE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3DC*/ { "CMSG_DEL_VOICE_IGNORE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3DD*/ { "CMSG_PARTY_SILENCE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3DE*/ { "CMSG_PARTY_UNSILENCE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3DF*/ { "MSG_NOTIFY_PARTY_SQUELCH",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3E0*/ { "SMSG_COMSAT_RECONNECT_TRY",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3E1*/ { "SMSG_COMSAT_DISCONNECT",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3E2*/ { "SMSG_COMSAT_CONNECT_FAIL",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3E3*/ { "SMSG_VOICE_CHAT_STATUS",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3E4*/ { "CMSG_REPORT_PVP_AFK",                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReportPvPAFK              },
    /*0x3E5*/ { "SMSG_REPORT_PVP_AFK_RESULT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3E6*/ { "CMSG_GUILD_BANKER_ACTIVATE",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankerActivate       },
    /*0x3E7*/ { "CMSG_GUILD_BANK_QUERY_TAB",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankQueryTab         },
    /*0x3E8*/ { "SMSG_GUILD_BANK_LIST",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3E9*/ { "CMSG_GUILD_BANK_SWAP_ITEMS",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankSwapItems        },
    /*0x3EA*/ { "CMSG_GUILD_BANK_BUY_TAB",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankBuyTab           },
    /*0x3EB*/ { "CMSG_GUILD_BANK_UPDATE_TAB",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankUpdateTab        },
    /*0x3EC*/ { "CMSG_GUILD_BANK_DEPOSIT_MONEY",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankDepositMoney     },
    /*0x3ED*/ { "CMSG_GUILD_BANK_WITHDRAW_MONEY",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankWithdrawMoney    },
    /*0x3EE*/ { "MSG_GUILD_BANK_LOG_QUERY",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankLogQuery         },
    /*0x3EF*/ { "CMSG_SET_CHANNEL_WATCH",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetChannelWatchOpcode     },
    /*0x3F0*/ { "SMSG_USERLIST_ADD",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3F1*/ { "SMSG_USERLIST_REMOVE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3F2*/ { "SMSG_USERLIST_UPDATE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3F3*/ { "CMSG_CLEAR_CHANNEL_WATCH",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3F4*/ { "SMSG_INSPECT_RESULTS",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3F5*/ { "SMSG_GOGOGO_OBSOLETE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3F6*/ { "SMSG_ECHO_PARTY_SQUELCH",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3F7*/ { "CMSG_SET_TITLE_SUFFIX",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3F8*/ { "CMSG_SPELLCLICK",                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSpellClick                },
    /*0x3F9*/ { "SMSG_LOOT_LIST",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3FA*/ { "CMSG_GM_CHARACTER_RESTORE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3FB*/ { "CMSG_GM_CHARACTER_SAVE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x3FC*/ { "SMSG_VOICESESSION_FULL",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x3FD*/ { "MSG_GUILD_PERMISSIONS",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPermissions          },
    /*0x3FE*/ { "MSG_GUILD_BANK_MONEY_WITHDRAWN",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankMoneyWithdrawn   },
    /*0x3FF*/ { "MSG_GUILD_EVENT_LOG_QUERY",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildEventLogQueryOpcode  },
    /*0x400*/ { "CMSG_MAELSTROM_RENAME_GUILD",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x401*/ { "CMSG_GET_MIRRORIMAGE_DATA",                    STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleGetMirrorimageData        },
    /*0x402*/ { "SMSG_MIRRORIMAGE_DATA",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x403*/ { "SMSG_FORCE_DISPLAY_UPDATE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x404*/ { "SMSG_SPELL_CHANCE_RESIST_PUSHBACK",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x405*/ { "CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT",        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x406*/ { "SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT",        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x407*/ { "CMSG_KEEP_ALIVE",                              STATUS_NEVER,    PROCESS_THREADUNSAFE, &WorldSession::Handle_EarlyProccess            },
    /*0x408*/ { "SMSG_RAID_READY_CHECK_ERROR",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x409*/ { "CMSG_OPT_OUT_OF_LOOT",                         STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleOptOutOfLootOpcode        },
    /*0x40A*/ { "MSG_QUERY_GUILD_BANK_TEXT",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryGuildBankTabText     },
    /*0x40B*/ { "CMSG_SET_GUILD_BANK_TEXT",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetGuildBankTabText       },
    /*0x40C*/ { "CMSG_SET_GRANTABLE_LEVELS",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x40D*/ { "CMSG_GRANT_LEVEL",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGrantLevel                },
    /*0x40E*/ { "CMSG_REFER_A_FRIEND",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x40F*/ { "MSG_GM_CHANGE_ARENA_RATING",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x410*/ { "CMSG_DECLINE_CHANNEL_INVITE",                  STATUS_UNHANDLED,PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x411*/ { "SMSG_GROUPACTION_THROTTLED",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x412*/ { "SMSG_OVERRIDE_LIGHT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x413*/ { "SMSG_TOTEM_CREATED",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x414*/ { "CMSG_TOTEM_DESTROYED",                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTotemDestroyed            },
    /*0x415*/ { "CMSG_EXPIRE_RAID_INSTANCE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x416*/ { "CMSG_NO_SPELL_VARIANCE",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x417*/ { "CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY",        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverStatusMultipleQuery},
    /*0x418*/ { "SMSG_QUESTGIVER_STATUS_MULTIPLE",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x419*/ { "CMSG_SET_PLAYER_DECLINED_NAMES",               STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetPlayerDeclinedNamesOpcode},
    /*0x41A*/ { "SMSG_SET_PLAYER_DECLINED_NAMES_RESULT",        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x41B*/ { "CMSG_QUERY_SERVER_BUCK_DATA",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x41C*/ { "CMSG_CLEAR_SERVER_BUCK_DATA",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x41D*/ { "SMSG_SERVER_BUCK_DATA",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x41E*/ { "SMSG_SEND_UNLEARN_SPELLS",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x41F*/ { "SMSG_PROPOSE_LEVEL_GRANT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x420*/ { "CMSG_ACCEPT_LEVEL_GRANT",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAcceptGrantLevel          },
    /*0x421*/ { "SMSG_REFER_A_FRIEND_ERROR",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x422*/ { "SMSG_SPLINE_MOVE_SET_FLYING",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x423*/ { "SMSG_SPLINE_MOVE_UNSET_FLYING",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x424*/ { "SMSG_SUMMON_CANCEL",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x425*/ { "CMSG_CHANGE_PERSONAL_ARENA_RATING",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x426*/ { "CMSG_ALTER_APPEARANCE",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAlterAppearanceOpcode     },
    /*0x427*/ { "SMSG_ENABLE_BARBER_SHOP",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x428*/ { "SMSG_BARBER_SHOP_RESULT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x429*/ { "CMSG_CALENDAR_GET_CALENDAR",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetCalendar       },
    /*0x42A*/ { "CMSG_CALENDAR_GET_EVENT",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetEvent          },
    /*0x42B*/ { "CMSG_CALENDAR_GUILD_FILTER",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGuildFilter       },
    /*0x42C*/ { "CMSG_CALENDAR_ARENA_TEAM",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarArenaTeam         },
    /*0x42D*/ { "CMSG_CALENDAR_ADD_EVENT",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarAddEvent          },
    /*0x42E*/ { "CMSG_CALENDAR_UPDATE_EVENT",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarUpdateEvent       },
    /*0x42F*/ { "CMSG_CALENDAR_REMOVE_EVENT",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarRemoveEvent       },
    /*0x430*/ { "CMSG_CALENDAR_COPY_EVENT",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarCopyEvent         },
    /*0x431*/ { "CMSG_CALENDAR_EVENT_INVITE",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventInvite       },
    /*0x432*/ { "CMSG_CALENDAR_EVENT_RSVP",                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRsvp         },
    /*0x433*/ { "CMSG_CALENDAR_EVENT_REMOVE_INVITE",            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRemoveInvite },
    /*0x434*/ { "CMSG_CALENDAR_EVENT_STATUS",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventStatus       },
    /*0x435*/ { "CMSG_CALENDAR_EVENT_MODERATOR_STATUS",         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventModeratorStatus},
    /*0x436*/ { "SMSG_CALENDAR_SEND_CALENDAR",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x437*/ { "SMSG_CALENDAR_SEND_EVENT",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x438*/ { "SMSG_CALENDAR_FILTER_GUILD",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x439*/ { "SMSG_CALENDAR_ARENA_TEAM",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x43A*/ { "SMSG_CALENDAR_EVENT_INVITE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x43B*/ { "SMSG_CALENDAR_EVENT_INVITE_REMOVED",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x43C*/ { "SMSG_CALENDAR_EVENT_STATUS",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x43D*/ { "SMSG_CALENDAR_COMMAND_RESULT",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x43E*/ { "SMSG_CALENDAR_RAID_LOCKOUT_ADDED",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x43F*/ { "SMSG_CALENDAR_RAID_LOCKOUT_REMOVED",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x440*/ { "SMSG_CALENDAR_EVENT_INVITE_ALERT",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x441*/ { "SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT",     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x442*/ { "SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT",      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x443*/ { "SMSG_CALENDAR_EVENT_REMOVED_ALERT",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x444*/ { "SMSG_CALENDAR_EVENT_UPDATED_ALERT",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x445*/ { "SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT",   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x446*/ { "CMSG_CALENDAR_COMPLAIN",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarComplain          },
    /*0x447*/ { "CMSG_CALENDAR_GET_NUM_PENDING",                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetNumPending     },
    /*0x448*/ { "SMSG_CALENDAR_SEND_NUM_PENDING",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x449*/ { "CMSG_SAVE_DANCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x44A*/ { "SMSG_NOTIFY_DANCE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x44B*/ { "CMSG_PLAY_DANCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x44C*/ { "SMSG_PLAY_DANCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x44D*/ { "CMSG_LOAD_DANCES",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x44E*/ { "CMSG_STOP_DANCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x44F*/ { "SMSG_STOP_DANCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x450*/ { "CMSG_SYNC_DANCE",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x451*/ { "CMSG_DANCE_QUERY",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x452*/ { "SMSG_DANCE_QUERY_RESPONSE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x453*/ { "SMSG_INVALIDATE_DANCE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x454*/ { "CMSG_DELETE_DANCE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x455*/ { "SMSG_LEARNED_DANCE_MOVES",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x456*/ { "CMSG_LEARN_DANCE_MOVE",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x457*/ { "CMSG_UNLEARN_DANCE_MOVE",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x458*/ { "CMSG_SET_RUNE_COUNT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x459*/ { "CMSG_SET_RUNE_COOLDOWN",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x45A*/ { "MSG_MOVE_SET_PITCH_RATE_CHEAT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x45B*/ { "MSG_MOVE_SET_PITCH_RATE",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x45C*/ { "SMSG_FORCE_PITCH_RATE_CHANGE",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x45D*/ { "CMSG_FORCE_PITCH_RATE_CHANGE_ACK",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x45E*/ { "SMSG_SPLINE_SET_PITCH_RATE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x45F*/ { "CMSG_CALENDAR_EVENT_INVITE_NOTES",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x460*/ { "SMSG_CALENDAR_EVENT_INVITE_NOTES",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x461*/ { "SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT",       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x462*/ { "CMSG_UPDATE_MISSILE_TRAJECTORY",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x463*/ { "SMSG_UPDATE_ACCOUNT_DATA_COMPLETE",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x464*/ { "SMSG_TRIGGER_MOVIE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x465*/ { "CMSG_COMPLETE_MOVIE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x466*/ { "CMSG_SET_GLYPH_SLOT",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x467*/ { "CMSG_SET_GLYPH",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x468*/ { "SMSG_ACHIEVEMENT_EARNED",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x469*/ { "SMSG_DYNAMIC_DROP_ROLL_RESULT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x46A*/ { "SMSG_CRITERIA_UPDATE",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x46B*/ { "CMSG_QUERY_INSPECT_ACHIEVEMENTS",              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryInspectAchievementsOpcode},
    /*0x46C*/ { "SMSG_RESPOND_INSPECT_ACHIEVEMENTS",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x46D*/ { "CMSG_DISMISS_CONTROLLED_VEHICLE",              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDismissControlledVehicle  },
    /*0x46E*/ { "CMSG_COMPLETE_ACHIEVEMENT_CHEAT",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x46F*/ { "SMSG_QUESTUPDATE_ADD_PVP_KILL",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x470*/ { "CMSG_SET_CRITERIA_CHEAT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x471*/ { "SMSG_CALENDAR_RAID_LOCKOUT_UPDATED",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x472*/ { "CMSG_UNITANIMTIER_CHEAT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x473*/ { "CMSG_CHAR_CUSTOMIZE",                          STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharCustomizeOpcode       },
    /*0x474*/ { "SMSG_CHAR_CUSTOMIZE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x475*/ { "SMSG_PET_RENAMEABLE",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x476*/ { "CMSG_REQUEST_VEHICLE_EXIT",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestVehicleExit        },
    /*0x477*/ { "CMSG_REQUEST_VEHICLE_PREV_SEAT",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestVehiclePrevSeat    },
    /*0x478*/ { "CMSG_REQUEST_VEHICLE_NEXT_SEAT",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestVehicleNextSeat    },
    /*0x479*/ { "CMSG_REQUEST_VEHICLE_SWITCH_SEAT",             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestVehicleSwitchSeat  },
    /*0x47A*/ { "CMSG_PET_LEARN_TALENT",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetLearnTalent            },
    /*0x47B*/ { "CMSG_PET_UNLEARN_TALENTS",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x47C*/ { "SMSG_SET_PHASE_SHIFT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x47D*/ { "SMSG_ALL_ACHIEVEMENT_DATA",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x47E*/ { "CMSG_FORCE_SAY_CHEAT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x47F*/ { "SMSG_HEALTH_UPDATE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x480*/ { "SMSG_POWER_UPDATE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x481*/ { "CMSG_GAMEOBJ_REPORT_USE",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameobjectReportUse       },
    /*0x482*/ { "SMSG_HIGHEST_THREAT_UPDATE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x483*/ { "SMSG_THREAT_UPDATE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x484*/ { "SMSG_THREAT_REMOVE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x485*/ { "SMSG_THREAT_CLEAR",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x486*/ { "SMSG_CONVERT_RUNE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x487*/ { "SMSG_RESYNC_RUNES",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x488*/ { "SMSG_ADD_RUNE_POWER",                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x489*/ { "CMSG_START_QUEST",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x48A*/ { "CMSG_REMOVE_GLYPH",                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRemoveGlyphOpcode         },
    /*0x48B*/ { "CMSG_DUMP_OBJECTS",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x48C*/ { "SMSG_DUMP_OBJECTS_DATA",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x48D*/ { "CMSG_DISMISS_CRITTER",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x48E*/ { "SMSG_NOTIFY_DEST_LOC_SPELL_CAST",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x48F*/ { "CMSG_AUCTION_LIST_PENDING_SALES",              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListPendingSales   },
    /*0x490*/ { "SMSG_AUCTION_LIST_PENDING_SALES",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x491*/ { "SMSG_MODIFY_COOLDOWN",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x492*/ { "SMSG_PET_UPDATE_COMBO_POINTS",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x493*/ { "CMSG_ENABLETAXI",                              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiQueryAvailableNodes   },
    /*0x494*/ { "SMSG_PRE_RESURRECT",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x495*/ { "SMSG_AURA_UPDATE_ALL",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x496*/ { "SMSG_AURA_UPDATE",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x497*/ { "CMSG_FLOOD_GRACE_CHEAT",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x498*/ { "SMSG_SERVER_FIRST_ACHIEVEMENT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x499*/ { "SMSG_PET_LEARNED_SPELL",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x49A*/ { "SMSG_PET_REMOVED_SPELL",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x49B*/ { "CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE",      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChangeSeatsOnControlledVehicle},
    /*0x49C*/ { "CMSG_HEARTH_AND_RESURRECT",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleHearthandResurrect        },
    /*0x49D*/ { "SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA",    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x49E*/ { "SMSG_CRITERIA_DELETED",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x49F*/ { "SMSG_ACHIEVEMENT_DELETED",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4A0*/ { "CMSG_SERVER_INFO_QUERY",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4A1*/ { "SMSG_SERVER_INFO_RESPONSE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4A2*/ { "CMSG_CHECK_LOGIN_CRITERIA",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4A3*/ { "SMSG_SERVER_BUCK_DATA_START",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4A4*/ { "CMSG_SET_BREATH",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4A5*/ { "CMSG_QUERY_VEHICLE_STATUS",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4A6*/ { "SMSG_BATTLEGROUND_INFO_THROTTLED",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4A7*/ { "SMSG_SET_VEHICLE_REC_ID",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4A8*/ { "CMSG_RIDE_VEHICLE_INTERACT",                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEnterPlayerVehicle        },
    /*0x4A9*/ { "CMSG_CONTROLLER_EJECT_PASSENGER",              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEjectPassenger            },
    /*0x4AA*/ { "SMSG_PET_GUIDS",                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4AB*/ { "SMSG_CLIENTCACHE_VERSION",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4AC*/ { "CMSG_CHANGE_GDF_ARENA_RATING",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4AD*/ { "CMSG_SET_ARENA_TEAM_RATING_BY_INDEX",          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4AE*/ { "CMSG_SET_ARENA_TEAM_WEEKLY_GAMES",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4AF*/ { "CMSG_SET_ARENA_TEAM_SEASON_GAMES",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4B0*/ { "CMSG_SET_ARENA_MEMBER_WEEKLY_GAMES",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4B1*/ { "CMSG_SET_ARENA_MEMBER_SEASON_GAMES",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4B2*/ { "SMSG_ITEM_REFUND_INFO_RESPONSE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4B3*/ { "CMSG_ITEM_REFUND_INFO",                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefundInfoRequest     },
    /*0x4B4*/ { "CMSG_ITEM_REFUND",                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefund                },
    /*0x4B5*/ { "SMSG_ITEM_REFUND_RESULT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4B6*/ { "CMSG_CORPSE_TRANSPORT_QUERY",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseMapPositionQueryOpcode},
    /*0x4B7*/ { "SMSG_CORPSE_TRANSPORT_QUERY",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4B8*/ { "CMSG_UNUSED5",                                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::Handle_NULL                     },
    /*0x4B9*/ { "CMSG_UNUSED6",                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4BA*/ { "CMSG_CALENDAR_EVENT_SIGNUP",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4BB*/ { "SMSG_CALENDAR_CLEAR_PENDING_ACTION",           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4BC*/ { "SMSG_LOAD_EQUIPMENT_SET",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4BD*/ { "CMSG_SAVE_EQUIPMENT_SET",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetSaveOpcode    },
    /*0x4BE*/ { "CMSG_ON_MISSILE_TRAJECTORY_COLLISION",         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4BF*/ { "SMSG_NOTIFY_MISSILE_TRAJECTORY_COLLISION",     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4C0*/ { "SMSG_TALENT_UPDATE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4C1*/ { "CMSG_LEARN_TALENT_GROUP",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalents       },
    /*0x4C2*/ { "CMSG_PET_LEARN_TALENT_GROUP",                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalentsPet    },
    /*0x4C3*/ { "CMSG_SET_ACTIVE_TALENT_GROUP_OBSOLETE",        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4C4*/ { "CMSG_GM_GRANT_ACHIEVEMENT",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4C5*/ { "CMSG_GM_REMOVE_ACHIEVEMENT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4C6*/ { "CMSG_GM_SET_CRITERIA_FOR_PLAYER",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4C7*/ { "SMSG_DESTROY_ARENA_UNIT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4C8*/ { "SMSG_ARENA_TEAM_CHANGE_FAILED",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4C9*/ { "CMSG_PROFILEDATA_REQUEST",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4CA*/ { "SMSG_PROFILEDATA_RESPONSE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4CB*/ { "CMSG_START_BATTLEFIELD_CHEAT",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4CC*/ { "CMSG_END_BATTLEFIELD_CHEAT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4CD*/ { "SMSG_COMPOUND_MOVE",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4CE*/ { "SMSG_MOVE_GRAVITY_DISABLE",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4CF*/ { "CMSG_MOVE_GRAVITY_DISABLE_ACK",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4D0*/ { "SMSG_MOVE_GRAVITY_ENABLE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4D1*/ { "CMSG_MOVE_GRAVITY_ENABLE_ACK",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4D2*/ { "MSG_MOVE_GRAVITY_CHNG",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4D3*/ { "SMSG_SPLINE_MOVE_GRAVITY_DISABLE",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4D4*/ { "SMSG_SPLINE_MOVE_GRAVITY_ENABLE",              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4D5*/ { "CMSG_USE_EQUIPMENT_SET",                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetUseOpcode     },
    /*0x4D6*/ { "SMSG_USE_EQUIPMENT_SET_RESULT",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4D7*/ { "CMSG_FORCE_ANIM",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4D8*/ { "SMSG_FORCE_ANIM",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4D9*/ { "CMSG_CHAR_FACTION_CHANGE",                     STATUS_AUTHED,   PROCESS_INPLACE,      &WorldSession::HandleCharFactionOrRaceChangeOpcode},
    /*0x4DA*/ { "SMSG_CHAR_FACTION_CHANGE",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4DB*/ { "CMSG_PVP_QUEUE_STATS_REQUEST",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4DC*/ { "SMSG_PVP_QUEUE_STATS",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4DD*/ { "CMSG_SET_PAID_SERVICE_CHEAT",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4DE*/ { "SMSG_BATTLEFIELD_MANAGER_ENTRY_INVITE",        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4DF*/ { "CMSG_BATTLEFIELD_MANAGER_ENTRY_INVITE_RESPONSE",STATUS_LOGGEDIN,PROCESS_INPLACE,      &WorldSession::HandleBfEntryInviteResponse     },
    /*0x4E0*/ { "SMSG_BATTLEFIELD_MANAGER_ENTERING",            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4E1*/ { "SMSG_BATTLEFIELD_MANAGER_QUEUE_INVITE",        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4E2*/ { "CMSG_BATTLEFIELD_MANAGER_QUEUE_INVITE_RESPONSE",STATUS_LOGGEDIN,PROCESS_INPLACE,      &WorldSession::HandleBfQueueInviteResponse     },
    /*0x4E3*/ { "CMSG_BATTLEFIELD_MANAGER_QUEUE_REQUEST",       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4E4*/ { "SMSG_BATTLEFIELD_MANAGER_QUEUE_REQUEST_RESPONSE",STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4E5*/ { "SMSG_BATTLEFIELD_MANAGER_EJECT_PENDING",       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4E6*/ { "SMSG_BATTLEFIELD_MANAGER_EJECTED",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4E7*/ { "CMSG_BATTLEFIELD_MANAGER_EXIT_REQUEST",        STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleBfExitRequest             },
    /*0x4E8*/ { "SMSG_BATTLEFIELD_MANAGER_STATE_CHANGED",       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4E9*/ { "CMSG_BATTLEFIELD_MANAGER_ADVANCE_STATE",       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4EA*/ { "CMSG_BATTLEFIELD_MANAGER_SET_NEXT_TRANSITION_TIME",STATUS_NEVER,PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4EB*/ { "MSG_SET_RAID_DIFFICULTY",                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetRaidDifficultyOpcode   },
    /*0x4EC*/ { "CMSG_XPGAIN",                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4ED*/ { "SMSG_XPGAIN",                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4EE*/ { "SMSG_GMTICKET_RESPONSE_ERROR",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4EF*/ { "SMSG_GMTICKET_GET_RESPONSE",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4F0*/ { "CMSG_GMTICKET_RESOLVE_RESPONSE",               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMResponseResolveOpcode   },
    /*0x4F1*/ { "SMSG_GMTICKET_RESOLVE_RESPONSE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4F2*/ { "SMSG_GMTICKET_CREATE_RESPONSE_TICKET",         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4F3*/ { "CMSG_GM_CREATE_TICKET_RESPONSE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4F4*/ { "CMSG_SERVERINFO",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4F5*/ { "SMSG_SERVERINFO",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4F6*/ { "CMSG_UI_TIME_REQUEST",                         STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleUITimeRequestOpcode       },
    /*0x4F7*/ { "SMSG_UI_TIME",                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4F8*/ { "CMSG_CHAR_RACE_CHANGE",                        STATUS_AUTHED,   PROCESS_INPLACE,      &WorldSession::HandleCharFactionOrRaceChangeOpcode},
    /*0x4F9*/ { "MSG_VIEW_PHASE_SHIFT",                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4FA*/ { "SMSG_TALENTS_INVOLUNTARILY_RESET",             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4FB*/ { "CMSG_DEBUG_SERVER_GEO",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4FC*/ { "SMSG_DEBUG_SERVER_GEO",                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4FD*/ { "SMSG_LOOT_UPDATE",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x4FE*/ { "UMSG_UPDATE_GROUP_INFO",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x4FF*/ { "CMSG_READY_FOR_ACCOUNT_DATA_TIMES",            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleReadyForAccountDataTimesOpcode},
    /*0x500*/ { "CMSG_QUERY_GET_ALL_QUESTS",                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryQuestsCompletedOpcode},
    /*0x501*/ { "SMSG_ALL_QUESTS_COMPLETED",                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x502*/ { "CMSG_GMLAGREPORT_SUBMIT",                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x503*/ { "CMSG_AFK_MONITOR_INFO_REQUEST",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x504*/ { "SMSG_AFK_MONITOR_INFO_RESPONSE",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x505*/ { "CMSG_AFK_MONITOR_INFO_CLEAR",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x506*/ { "SMSG_AREA_TRIGGER_NO_CORPSE",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x507*/ { "CMSG_GM_NUKE_CHARACTER",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x508*/ { "CMSG_LOW_LEVEL_RAID",                          STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetAllowLowLevelRaidOpcode},
    /*0x509*/ { "CMSG_LOW_LEVEL_RAID_USER",                     STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetAllowLowLevelRaidOpcode},
    /*0x50A*/ { "SMSG_CAMERA_SHAKE",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x50B*/ { "SMSG_SOCKET_GEMS",                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x50C*/ { "CMSG_SET_CHARACTER_MODEL",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x50D*/ { "SMSG_CONNECT_TO",                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x50E*/ { "CMSG_CONNECT_TO_FAILED",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x50F*/ { "SMSG_SUSPEND_COMMS",                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x510*/ { "CMSG_SUSPEND_COMMS_ACK",                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x511*/ { "SMSG_RESUME_COMMS",                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x512*/ { "CMSG_AUTH_CONTINUED_SESSION",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x513*/ { "CMSG_DROP_NEW_CONNECTION",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x514*/ { "SMSG_SEND_ALL_COMBAT_LOG",                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x515*/ { "SMSG_OPEN_LFG_DUNGEON_FINDER",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x516*/ { "SMSG_MOVE_SET_COLLISION_HGT",                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x517*/ { "CMSG_MOVE_SET_COLLISION_HGT_ACK",              STATUS_UNHANDLED,PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x518*/ { "MSG_MOVE_SET_COLLISION_HGT",                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x519*/ { "CMSG_CLEAR_RANDOM_BG_WIN_TIME",                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x51A*/ { "CMSG_CLEAR_HOLIDAY_BG_WIN_TIME",               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x51B*/ { "CMSG_COMMENTATOR_SKIRMISH_QUEUE_COMMAND",      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     },
    /*0x51C*/ { "SMSG_COMMENTATOR_SKIRMISH_QUEUE_RESULT1",      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x51D*/ { "SMSG_COMMENTATOR_SKIRMISH_QUEUE_RESULT2",      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
    /*0x51E*/ { "SMSG_COMPRESSED_UNKNOWN_1310",                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               },
=======
    for(uint16 i = 0; i < MAX_OPCODE_TABLE_SIZE; ++i)
        DefineOpcode(i, "UNKNOWN", STATUS_UNHANDLED, PROCESS_INPLACE, &WorldSession::Handle_NULL);

    OPCODE(MSG_WOW_CONNECTION,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_EarlyProccess            );
    OPCODE(SMSG_AUTH_CHALLENGE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(CMSG_AUTH_SESSION,                              STATUS_NEVER,    PROCESS_THREADUNSAFE, &WorldSession::Handle_EarlyProccess            );
    OPCODE(SMSG_AUTH_RESPONSE,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_NULL_ACTION,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_BOOTME,                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DBLOOKUP,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DBLOOKUP,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUERY_OBJECT_POSITION,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_QUERY_OBJECT_POSITION,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUERY_OBJECT_ROTATION,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_QUERY_OBJECT_ROTATION,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_WORLD_TELEPORT,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWorldTeleportOpcode       );
    //OPCODE(CMSG_TELEPORT_TO_UNIT,                        STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ZONE_MAP,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_ZONE_MAP,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DEBUG_CHANGECELLZONE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_MOVE_CHARACTER_CHEAT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_MOVE_CHARACTER_CHEAT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_RECHARGE,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_LEARN_SPELL,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CREATEMONSTER,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DESTROYMONSTER,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CREATEITEM,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CREATEGAMEOBJECT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CHECK_FOR_BOTS,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MAKEMONSTERATTACKGUID,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_BOT_DETECTED2,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_FORCEACTION,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_FORCEACTIONONOTHER,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_FORCEACTIONSHOW,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCEACTIONSHOW,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PETGODMODE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PETGODMODE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_REFER_A_FRIEND_EXPIRED,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_WEATHER_SPEED_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_UNDRESSPLAYER,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_BEASTMASTER,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GODMODE,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GODMODE,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHEAT_SETMONEY,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_LEVEL_CHEAT,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_PET_LEVEL_CHEAT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_WORLDSTATE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_COOLDOWN_CHEAT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_USE_SKILL_CHEAT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_FLAG_QUEST,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_FLAG_QUEST_FINISH,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CLEAR_QUEST,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SEND_EVENT,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DEBUG_AISTATE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DEBUG_AISTATE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DISABLE_PVP_CHEAT,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ADVANCE_SPAWN_TIME,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DESTRUCTIBLE_BUILDING_DAMAGE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTH_SRP6_BEGIN,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTH_SRP6_PROOF,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTH_SRP6_RECODE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    OPCODE(CMSG_CHAR_CREATE,                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharCreateOpcode          );
    OPCODE(CMSG_CHAR_ENUM,                               STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharEnumOpcode            );
    OPCODE(CMSG_CHAR_DELETE,                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharDeleteOpcode          );
    //OPCODE(SMSG_AUTH_SRP6_RESPONSE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_CHAR_CREATE,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_CHAR_ENUM,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_CHAR_DELETE,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(CMSG_PLAYER_LOGIN,                            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLoginOpcode         );
    //OPCODE(SMSG_NEW_WORLD,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TRANSFER_PENDING,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TRANSFER_ABORTED,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHARACTER_LOGIN_FAILED,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_LOGIN_SETTIMESPEED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GAMETIME_UPDATE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GAMETIME_SET,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GAMETIME_SET,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GAMESPEED_SET,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GAMESPEED_SET,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SERVERTIME,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SERVERTIME,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PLAYER_LOGOUT,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayerLogoutOpcode        );
    //OPCODE(CMSG_LOGOUT_REQUEST,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutRequestOpcode       );
    //OPCODE(SMSG_LOGOUT_RESPONSE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOGOUT_COMPLETE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LOGOUT_CANCEL,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLogoutCancelOpcode        );
    //OPCODE(SMSG_LOGOUT_CANCEL_ACK,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_NAME_QUERY,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNameQueryOpcode           );
    //OPCODE(SMSG_NAME_QUERY_RESPONSE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PET_NAME_QUERY,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetNameQueryOpcode        );
    //OPCODE(SMSG_PET_NAME_QUERY_RESPONSE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_QUERY,                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleGuildQueryOpcode          );
    //OPCODE(SMSG_GUILD_QUERY_RESPONSE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ITEM_QUERY_SINGLE,                       STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleItemQuerySingleOpcode     );
    //OPCODE(CMSG_ITEM_QUERY_MULTIPLE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_ITEM_QUERY_SINGLE_RESPONSE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ITEM_QUERY_MULTIPLE_RESPONSE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PAGE_TEXT_QUERY,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePageTextQueryOpcode       );
    //OPCODE(SMSG_PAGE_TEXT_QUERY_RESPONSE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUEST_QUERY,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestQueryOpcode          );
    //OPCODE(SMSG_QUEST_QUERY_RESPONSE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GAMEOBJECT_QUERY,                        STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleGameObjectQueryOpcode     );
    //OPCODE(SMSG_GAMEOBJECT_QUERY_RESPONSE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CREATURE_QUERY,                          STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleCreatureQueryOpcode       );
    //OPCODE(SMSG_CREATURE_QUERY_RESPONSE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_WHO,                                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoOpcode                 );
    //OPCODE(SMSG_WHO,                                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_WHOIS,                                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWhoisOpcode               );
    //OPCODE(SMSG_WHOIS,                                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CONTACT_LIST,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleContactListOpcode         );
    //OPCODE(SMSG_CONTACT_LIST,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_FRIEND_STATUS,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ADD_FRIEND,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAddFriendOpcode           );
    //OPCODE(CMSG_DEL_FRIEND,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDelFriendOpcode           );
    //OPCODE(CMSG_SET_CONTACT_NOTES,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetContactNotesOpcode     );
    //OPCODE(CMSG_ADD_IGNORE,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAddIgnoreOpcode           );
    //OPCODE(CMSG_DEL_IGNORE,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDelIgnoreOpcode           );
    //OPCODE(CMSG_GROUP_INVITE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupInviteOpcode         );
    //OPCODE(SMSG_GROUP_INVITE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GROUP_CANCEL,                            STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GROUP_CANCEL,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GROUP_ACCEPT,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAcceptOpcode         );
    //OPCODE(CMSG_GROUP_DECLINE,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDeclineOpcode        );
    //OPCODE(SMSG_GROUP_DECLINE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GROUP_UNINVITE,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteOpcode       );
    //OPCODE(CMSG_GROUP_UNINVITE_GUID,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupUninviteGuidOpcode   );
    //OPCODE(SMSG_GROUP_UNINVITE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GROUP_SET_LEADER,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupSetLeaderOpcode      );
    //OPCODE(SMSG_GROUP_SET_LEADER,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LOOT_METHOD,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMethodOpcode          );
    //OPCODE(CMSG_GROUP_DISBAND,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupDisbandOpcode        );
    //OPCODE(SMSG_GROUP_DESTROYED,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GROUP_LIST,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PARTY_MEMBER_STATS,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PARTY_COMMAND_RESULT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(UMSG_UPDATE_GROUP_MEMBERS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GUILD_CREATE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildCreateOpcode         );
    //OPCODE(CMSG_GUILD_INVITE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInviteOpcode         );
    //OPCODE(SMSG_GUILD_INVITE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_ACCEPT,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAcceptOpcode         );
    //OPCODE(CMSG_GUILD_DECLINE,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDeclineOpcode        );
    //OPCODE(SMSG_GUILD_DECLINE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_INFO,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildInfoOpcode           );
    //OPCODE(SMSG_GUILD_INFO,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_ROSTER,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRosterOpcode         );
    //OPCODE(SMSG_GUILD_ROSTER,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_PROMOTE,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPromoteOpcode        );
    //OPCODE(CMSG_GUILD_DEMOTE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDemoteOpcode         );
    //OPCODE(CMSG_GUILD_LEAVE,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaveOpcode          );
    //OPCODE(CMSG_GUILD_REMOVE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRemoveOpcode         );
    //OPCODE(CMSG_GUILD_DISBAND,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDisbandOpcode        );
    //OPCODE(CMSG_GUILD_LEADER,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildLeaderOpcode         );
    //OPCODE(CMSG_GUILD_MOTD,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildMOTDOpcode           );
    //OPCODE(SMSG_GUILD_EVENT,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GUILD_COMMAND_RESULT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(UMSG_UPDATE_GUILD,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_MESSAGECHAT,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMessagechatOpcode         );
    //OPCODE(SMSG_MESSAGECHAT,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_JOIN_CHANNEL,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleJoinChannelOpcode         );
    //OPCODE(CMSG_LEAVE_CHANNEL,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveChannelOpcode        );
    //OPCODE(SMSG_CHANNEL_NOTIFY,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANNEL_LIST,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelListOpcode         );
    //OPCODE(SMSG_CHANNEL_LIST,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANNEL_PASSWORD,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelPasswordOpcode     );
    //OPCODE(CMSG_CHANNEL_SET_OWNER,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelSetOwnerOpcode     );
    //OPCODE(CMSG_CHANNEL_OWNER,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelOwnerOpcode        );
    //OPCODE(CMSG_CHANNEL_MODERATOR,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelModeratorOpcode    );
    //OPCODE(CMSG_CHANNEL_UNMODERATOR,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmoderatorOpcode  );
    //OPCODE(CMSG_CHANNEL_MUTE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelMuteOpcode         );
    //OPCODE(CMSG_CHANNEL_UNMUTE,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnmuteOpcode       );
    //OPCODE(CMSG_CHANNEL_INVITE,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelInviteOpcode       );
    //OPCODE(CMSG_CHANNEL_KICK,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelKickOpcode         );
    //OPCODE(CMSG_CHANNEL_BAN,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelBanOpcode          );
    //OPCODE(CMSG_CHANNEL_UNBAN,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelUnbanOpcode        );
    //OPCODE(CMSG_CHANNEL_ANNOUNCEMENTS,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelAnnouncementsOpcode);
    //OPCODE(CMSG_CHANNEL_MODERATE,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelModerateOpcode     );
    //OPCODE(SMSG_UPDATE_OBJECT,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DESTROY_OBJECT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_USE_ITEM,                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUseItemOpcode             );
    //OPCODE(CMSG_OPEN_ITEM,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOpenItemOpcode            );
    //OPCODE(CMSG_READ_ITEM,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReadItemOpcode            );
    //OPCODE(SMSG_READ_ITEM_OK,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_READ_ITEM_FAILED,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ITEM_COOLDOWN,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GAMEOBJ_USE,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameObjectUseOpcode       );
    //OPCODE(CMSG_DESTROY_ITEMS,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GAMEOBJECT_CUSTOM_ANIM,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_AREATRIGGER,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaTriggerOpcode         );
    //OPCODE(MSG_MOVE_START_FORWARD,                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_BACKWARD,                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_STOP,                                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_STRAFE_LEFT,                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_STRAFE_RIGHT,                  STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_STOP_STRAFE,                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_JUMP,                                STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_TURN_LEFT,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_TURN_RIGHT,                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_STOP_TURN,                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_PITCH_UP,                      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_PITCH_DOWN,                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_STOP_PITCH,                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_SET_RUN_MODE,                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_SET_WALK_MODE,                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_TOGGLE_LOGGING,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_TELEPORT,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_TELEPORT_CHEAT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_TELEPORT_ACK,                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveTeleportAckOpcode     );
    //OPCODE(MSG_MOVE_TOGGLE_FALL_LOGGING,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_FALL_LAND,                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_START_SWIM,                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_STOP_SWIM,                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_SET_RUN_SPEED_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_RUN_SPEED,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_RUN_BACK_SPEED,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_WALK_SPEED_CHEAT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_WALK_SPEED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_SWIM_SPEED_CHEAT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_SWIM_SPEED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_SWIM_BACK_SPEED,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_ALL_SPEED_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_TURN_RATE_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_TURN_RATE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_TOGGLE_COLLISION_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_FACING,                          STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_SET_PITCH,                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_WORLDPORT_ACK,                       STATUS_TRANSFER, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveWorldportAckOpcode    );
    //OPCODE(SMSG_MONSTER_MOVE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_WATER_WALK,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_LAND_WALK,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_CHARM_PORT_CHEAT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_MOVE_SET_RAW_POSITION,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCE_RUN_SPEED_CHANGE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_RUN_SPEED_CHANGE_ACK,              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_FORCE_RUN_BACK_SPEED_CHANGE,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK,         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_FORCE_SWIM_SPEED_CHANGE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_SWIM_SPEED_CHANGE_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_FORCE_MOVE_ROOT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_MOVE_ROOT_ACK,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveRootAck               );
    //OPCODE(SMSG_FORCE_MOVE_UNROOT,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_MOVE_UNROOT_ACK,                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveUnRootAck             );
    //OPCODE(MSG_MOVE_ROOT,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_UNROOT,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_HEARTBEAT,                           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(SMSG_MOVE_KNOCK_BACK,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_KNOCK_BACK_ACK,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveKnockBackAck          );
    //OPCODE(MSG_MOVE_KNOCK_BACK,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_MOVE_FEATHER_FALL,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_NORMAL_FALL,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_SET_HOVER,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_UNSET_HOVER,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_HOVER_ACK,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMoveHoverAck              );
    //OPCODE(MSG_MOVE_HOVER,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_TRIGGER_CINEMATIC_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_OPENING_CINEMATIC,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    OPCODE(SMSG_TRIGGER_CINEMATIC,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_NEXT_CINEMATIC_CAMERA,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNextCinematicCamera       );
    //OPCODE(CMSG_COMPLETE_CINEMATIC,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCompleteCinematic         );
    OPCODE(SMSG_TUTORIAL_FLAGS,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TUTORIAL_FLAG,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialFlagOpcode        );
    //OPCODE(CMSG_TUTORIAL_CLEAR,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialClearOpcode       );
    //OPCODE(CMSG_TUTORIAL_RESET,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTutorialResetOpcode       );
    //OPCODE(CMSG_STANDSTATECHANGE,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStandStateChangeOpcode    );
    //OPCODE(CMSG_EMOTE,                                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEmoteOpcode               );
    //OPCODE(SMSG_EMOTE,                                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TEXT_EMOTE,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTextEmoteOpcode           );
    //OPCODE(SMSG_TEXT_EMOTE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_AUTOEQUIP_GROUND_ITEM,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTOSTORE_GROUND_ITEM,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTOSTORE_LOOT_ITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutostoreLootItemOpcode   );
    //OPCODE(CMSG_STORE_LOOT_IN_SLOT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTOEQUIP_ITEM,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemOpcode       );
    //OPCODE(CMSG_AUTOSTORE_BAG_ITEM,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBagItemOpcode    );
    //OPCODE(CMSG_SWAP_ITEM,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapItem                  );
    //OPCODE(CMSG_SWAP_INV_ITEM,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSwapInvItemOpcode         );
    //OPCODE(CMSG_SPLIT_ITEM,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSplitItemOpcode           );
    //OPCODE(CMSG_AUTOEQUIP_ITEM_SLOT,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoEquipItemSlotOpcode   );
    //OPCODE(CMSG_UNCLAIM_LICENSE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DESTROYITEM,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDestroyItemOpcode         );
    //OPCODE(SMSG_INVENTORY_CHANGE_FAILURE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_OPEN_CONTAINER,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_INSPECT,                                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectOpcode             );
    //OPCODE(SMSG_INSPECT_RESULTS_UPDATE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_INITIATE_TRADE,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInitiateTradeOpcode       );
    //OPCODE(CMSG_BEGIN_TRADE,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBeginTradeOpcode          );
    //OPCODE(CMSG_BUSY_TRADE,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBusyTradeOpcode           );
    //OPCODE(CMSG_IGNORE_TRADE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleIgnoreTradeOpcode         );
    //OPCODE(CMSG_ACCEPT_TRADE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAcceptTradeOpcode         );
    //OPCODE(CMSG_UNACCEPT_TRADE,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnacceptTradeOpcode       );
    //OPCODE(CMSG_CANCEL_TRADE,                            STATUS_LOGGEDIN_OR_RECENTLY_LOGGEDOUT, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTradeOpcode);
    //OPCODE(CMSG_SET_TRADE_ITEM,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeItemOpcode        );
    //OPCODE(CMSG_CLEAR_TRADE_ITEM,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleClearTradeItemOpcode      );
    //OPCODE(CMSG_SET_TRADE_GOLD,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTradeGoldOpcode        );
    //OPCODE(SMSG_TRADE_STATUS,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TRADE_STATUS_EXTENDED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_INITIALIZE_FACTIONS,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_FACTION_VISIBLE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_FACTION_STANDING,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_FACTION_ATWAR,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionAtWarOpcode           );
    //OPCODE(CMSG_SET_FACTION_CHEAT,                       STATUS_NEVER,    PROCESS_THREADUNSAFE, &WorldSession::Handle_Deprecated               );
    //OPCODE(SMSG_SET_PROFICIENCY,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_ACTION_BUTTON,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionButtonOpcode     );
    OPCODE(SMSG_ACTION_BUTTONS,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_INITIAL_SPELLS,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LEARNED_SPELL,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SUPERCEDED_SPELL,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_NEW_SPELL_SLOT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CAST_SPELL,                              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleCastSpellOpcode           );
    //OPCODE(CMSG_CANCEL_CAST,                             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleCancelCastOpcode          );
    //OPCODE(SMSG_CAST_FAILED,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_START,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_GO,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_FAILURE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_COOLDOWN,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COOLDOWN_EVENT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CANCEL_AURA,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelAuraOpcode          );
    //OPCODE(SMSG_EQUIPMENT_SET_ID,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_CAST_FAILED,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_CHANNEL_START,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_CHANNEL_UPDATE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CANCEL_CHANNELLING,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelChanneling          );
    //OPCODE(SMSG_AI_REACTION,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_SELECTION,                           STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetSelectionOpcode        );
    //OPCODE(CMSG_DELETEEQUIPMENT_SET,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetDeleteOpcode  );
    //OPCODE(CMSG_INSTANCE_LOCK_RESPONSE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DEBUG_PASSIVE_AURA,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ATTACKSWING,                             STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleAttackSwingOpcode         );
    //OPCODE(CMSG_ATTACKSTOP,                              STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleAttackStopOpcode          );
    //OPCODE(SMSG_ATTACKSTART,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ATTACKSTOP,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ATTACKSWING_NOTINRANGE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ATTACKSWING_BADFACING,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PENDING_RAID_LOCK,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ATTACKSWING_DEADTARGET,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ATTACKSWING_CANT_ATTACK,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ATTACKERSTATEUPDATE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BATTLEFIELD_PORT_DENIED,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PERFORM_ACTION_SET,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_RESUME_CAST_BAR,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CANCEL_COMBAT,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLBREAKLOG,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLHEALLOG,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLENERGIZELOG,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BREAK_TARGET,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SAVE_PLAYER,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SETDEATHBINDPOINT,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    OPCODE(SMSG_BINDPOINTUPDATE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GETDEATHBINDZONE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_BINDZONEREPLY,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PLAYERBOUND,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CLIENT_CONTROL_UPDATE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REPOP_REQUEST,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepopRequestOpcode        );
    //OPCODE(SMSG_RESURRECT_REQUEST,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_RESURRECT_RESPONSE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleResurrectResponseOpcode   );
    //OPCODE(CMSG_LOOT,                                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootOpcode                );
    //OPCODE(CMSG_LOOT_MONEY,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMoneyOpcode           );
    //OPCODE(CMSG_LOOT_RELEASE,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootReleaseOpcode         );
    //OPCODE(SMSG_LOOT_RESPONSE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_RELEASE_RESPONSE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_REMOVED,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_MONEY_NOTIFY,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_ITEM_NOTIFY,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_CLEAR_MONEY,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ITEM_PUSH_RESULT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DUEL_REQUESTED,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DUEL_OUTOFBOUNDS,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DUEL_INBOUNDS,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DUEL_COMPLETE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DUEL_WINNER,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DUEL_ACCEPTED,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelAcceptedOpcode        );
    //OPCODE(CMSG_DUEL_CANCELLED,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDuelCancelledOpcode       );
    //OPCODE(SMSG_MOUNTRESULT,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DISMOUNTRESULT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_REMOVED_FROM_PVP_QUEUE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOUNTSPECIAL_ANIM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMountSpecialAnimOpcode    );
    //OPCODE(SMSG_MOUNTSPECIAL_ANIM,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_TAME_FAILURE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PET_SET_ACTION,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSetAction              );
    //OPCODE(CMSG_PET_ACTION,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAction                 );
    //OPCODE(CMSG_PET_ABANDON,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetAbandon                );
    //OPCODE(CMSG_PET_RENAME,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetRename                 );
    //OPCODE(SMSG_PET_NAME_INVALID,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_SPELLS,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_MODE,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GOSSIP_HELLO,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipHelloOpcode         );
    //OPCODE(CMSG_GOSSIP_SELECT_OPTION,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGossipSelectOptionOpcode  );
    //OPCODE(SMSG_GOSSIP_MESSAGE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GOSSIP_COMPLETE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_NPC_TEXT_QUERY,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleNpcTextQueryOpcode        );
    //OPCODE(SMSG_NPC_TEXT_UPDATE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_NPC_WONT_TALK,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_STATUS_QUERY,                 STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleQuestgiverStatusQueryOpcode);
    //OPCODE(SMSG_QUESTGIVER_STATUS,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_HELLO,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverHelloOpcode     );
    //OPCODE(SMSG_QUESTGIVER_QUEST_LIST,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_QUERY_QUEST,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQueryQuestOpcode);
    //OPCODE(CMSG_QUESTGIVER_QUEST_AUTOLAUNCH,             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverQuestAutoLaunch );
    //OPCODE(SMSG_QUESTGIVER_QUEST_DETAILS,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_ACCEPT_QUEST,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverAcceptQuestOpcode);
    //OPCODE(CMSG_QUESTGIVER_COMPLETE_QUEST,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCompleteQuest   );
    //OPCODE(SMSG_QUESTGIVER_REQUEST_ITEMS,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_REQUEST_REWARD,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverRequestRewardOpcode);
    //OPCODE(SMSG_QUESTGIVER_OFFER_REWARD,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_CHOOSE_REWARD,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverChooseRewardOpcode);
    //OPCODE(SMSG_QUESTGIVER_QUEST_INVALID,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTGIVER_CANCEL,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverCancel          );
    //OPCODE(SMSG_QUESTGIVER_QUEST_COMPLETE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_QUESTGIVER_QUEST_FAILED,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUESTLOG_SWAP_QUEST,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogSwapQuest         );
    //OPCODE(CMSG_QUESTLOG_REMOVE_QUEST,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestLogRemoveQuest       );
    //OPCODE(SMSG_QUESTLOG_FULL,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_QUESTUPDATE_FAILED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_QUESTUPDATE_FAILEDTIMER,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_QUESTUPDATE_COMPLETE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_QUESTUPDATE_ADD_KILL,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_QUESTUPDATE_ADD_ITEM_OBSOLETE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUEST_CONFIRM_ACCEPT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestConfirmAccept        );
    //OPCODE(SMSG_QUEST_CONFIRM_ACCEPT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PUSHQUESTTOPARTY,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePushQuestToParty          );
    //OPCODE(CMSG_LIST_INVENTORY,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListInventoryOpcode       );
    //OPCODE(SMSG_LIST_INVENTORY,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SELL_ITEM,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSellItemOpcode            );
    //OPCODE(SMSG_SELL_ITEM,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BUY_ITEM,                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemOpcode             );
    //OPCODE(CMSG_BUY_ITEM_IN_SLOT,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyItemInSlotOpcode       );
    //OPCODE(SMSG_BUY_ITEM,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BUY_FAILED,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TAXICLEARALLNODES,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_TAXIENABLEALLNODES,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_TAXISHOWNODES,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SHOWTAXINODES,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TAXINODE_STATUS_QUERY,                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiNodeStatusQueryOpcode );
    //OPCODE(SMSG_TAXINODE_STATUS,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TAXIQUERYAVAILABLENODES,                 STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiQueryAvailableNodes   );
    //OPCODE(CMSG_ACTIVATETAXI,                            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleActivateTaxiOpcode        );
    //OPCODE(SMSG_ACTIVATETAXIREPLY,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_NEW_TAXI_PATH,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TRAINER_LIST,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerListOpcode         );
    //OPCODE(SMSG_TRAINER_LIST,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TRAINER_BUY_SPELL,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTrainerBuySpellOpcode     );
    //OPCODE(SMSG_TRAINER_BUY_SUCCEEDED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TRAINER_BUY_FAILED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BINDER_ACTIVATE,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBinderActivateOpcode      );
    //OPCODE(SMSG_PLAYERBINDERROR,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BANKER_ACTIVATE,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBankerActivateOpcode      );
    //OPCODE(SMSG_SHOW_BANK,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BUY_BANK_SLOT,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyBankSlotOpcode         );
    //OPCODE(SMSG_BUY_BANK_SLOT_RESULT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PETITION_SHOWLIST,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowListOpcode    );
    //OPCODE(SMSG_PETITION_SHOWLIST,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PETITION_BUY,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionBuyOpcode         );
    //OPCODE(CMSG_PETITION_SHOW_SIGNATURES,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionShowSignOpcode    );
    //OPCODE(SMSG_PETITION_SHOW_SIGNATURES,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PETITION_SIGN,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionSignOpcode        );
    //OPCODE(SMSG_PETITION_SIGN_RESULTS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_PETITION_DECLINE,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionDeclineOpcode     );
    //OPCODE(CMSG_OFFER_PETITION,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleOfferPetitionOpcode       );
    //OPCODE(CMSG_TURN_IN_PETITION,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTurnInPetitionOpcode      );
    //OPCODE(SMSG_TURN_IN_PETITION_RESULTS,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PETITION_QUERY,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionQueryOpcode       );
    //OPCODE(SMSG_PETITION_QUERY_RESPONSE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_FISH_NOT_HOOKED,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_FISH_ESCAPED,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BUG,                                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBugOpcode                 );
    //OPCODE(SMSG_NOTIFICATION,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PLAYED_TIME,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePlayedTime                );
    //OPCODE(SMSG_PLAYED_TIME,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUERY_TIME,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryTimeOpcode           );
    //OPCODE(SMSG_QUERY_TIME_RESPONSE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOG_XPGAIN,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AURACASTLOG,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_RECLAIM_CORPSE,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReclaimCorpseOpcode       );
    //OPCODE(CMSG_WRAP_ITEM,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWrapItemOpcode            );
    //OPCODE(SMSG_LEVELUP_INFO,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_MINIMAP_PING,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMinimapPingOpcode         );
    //OPCODE(SMSG_RESISTLOG,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ENCHANTMENTLOG,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_SKILL_CHEAT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_START_MIRROR_TIMER,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PAUSE_MIRROR_TIMER,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_STOP_MIRROR_TIMER,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PING,                                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_EarlyProccess            );
    //OPCODE(SMSG_PONG,                                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CLEAR_COOLDOWN,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GAMEOBJECT_PAGETEXT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SETSHEATHED,                             STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetSheathedOpcode         );
    //OPCODE(SMSG_COOLDOWN_CHEAT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_DELAYED,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUEST_POI_QUERY,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPOIQueryOpcode       );
    //OPCODE(SMSG_QUEST_POI_QUERY_RESPONSE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GHOST,                                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_INVIS,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_INVALID_PROMOTION_CODE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_GM_BIND_OTHER,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_GM_SUMMON,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_ITEM_TIME_UPDATE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ITEM_ENCHANT_TIME_UPDATE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_GM_SHOWLABEL,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_PET_CAST_SPELL,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetCastSpellOpcode        );
    //OPCODE(MSG_SAVE_GUILD_EMBLEM,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSaveGuildEmblemOpcode     );
    //OPCODE(MSG_TABARDVENDOR_ACTIVATE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTabardVendorActivateOpcode);
    //OPCODE(SMSG_PLAY_SPELL_VISUAL,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ZONEUPDATE,                              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleZoneUpdateOpcode          );
    //OPCODE(SMSG_PARTYKILLLOG,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMPRESSED_UPDATE_OBJECT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PLAY_SPELL_IMPACT,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_EXPLORATION_EXPERIENCE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_SET_SECURITY_GROUP,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_NUKE,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_RANDOM_ROLL,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRandomRollOpcode          );
    //OPCODE(SMSG_ENVIRONMENTALDAMAGELOG,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANGEPLAYER_DIFFICULTY,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_RWHOIS,                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_PLAYER_REWARD,                       STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_TELEPORT_DENIED,                     STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_UNLEARN_SPELL,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_UNLEARN_SKILL,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnlearnSkillOpcode        );
    //OPCODE(SMSG_REMOVED_SPELL,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DECHARGE,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GMTICKET_CREATE,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketCreateOpcode      );
    //OPCODE(SMSG_GMTICKET_CREATE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GMTICKET_UPDATETEXT,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketUpdateTextOpcode  );
    //OPCODE(SMSG_GMTICKET_UPDATETEXT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_ACCOUNT_DATA_TIMES,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REQUEST_ACCOUNT_DATA,                    STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleRequestAccountData        );
    //OPCODE(CMSG_UPDATE_ACCOUNT_DATA,                     STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleUpdateAccountData);
    //OPCODE(SMSG_UPDATE_ACCOUNT_DATA,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CLEAR_FAR_SIGHT_IMMEDIATE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHANGEPLAYER_DIFFICULTY_RESULT,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_TEACH,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_CREATE_ITEM_TARGET,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GMTICKET_GETTICKET,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketGetTicketOpcode   );
    //OPCODE(SMSG_GMTICKET_GETTICKET,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_UNLEARN_TALENTS,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_INSTANCE_ENCOUNTER,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GAMEOBJECT_DESPAWN_ANIM,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_CORPSE_QUERY,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseQueryOpcode         );
    //OPCODE(CMSG_GMTICKET_DELETETICKET,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketDeleteTicketOpcode);
    //OPCODE(SMSG_GMTICKET_DELETETICKET,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHAT_WRONG_FACTION,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GMTICKET_SYSTEMSTATUS,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMTicketSystemStatusOpcode);
    //OPCODE(SMSG_GMTICKET_SYSTEMSTATUS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SPIRIT_HEALER_ACTIVATE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSpiritHealerActivateOpcode);
    //OPCODE(CMSG_SET_STAT_CHEAT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_QUEST_FORCE_REMOVED,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SKILL_BUY_STEP,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SKILL_BUY_RANK,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_XP_CHEAT,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SPIRIT_HEALER_CONFIRM,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHARACTER_POINT_CHEAT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GOSSIP_POI,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHAT_IGNORED,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChatIgnoredOpcode         );
    //OPCODE(CMSG_GM_VISION,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SERVER_COMMAND,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_SILENCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_REVEALTO,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_RESURRECT,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_SUMMONMOB,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_MOVECORPSE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_FREEZE,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_UBERINVIS,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_REQUEST_PLAYER_INFO,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GM_PLAYER_INFO,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GUILD_RANK,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildRankOpcode           );
    //OPCODE(CMSG_GUILD_ADD_RANK,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildAddRankOpcode        );
    //OPCODE(CMSG_GUILD_DEL_RANK,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildDelRankOpcode        );
    //OPCODE(CMSG_GUILD_SET_PUBLIC_NOTE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetPublicNoteOpcode  );
    //OPCODE(CMSG_GUILD_SET_OFFICER_NOTE,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildSetOfficerNoteOpcode );
    OPCODE(SMSG_LOGIN_VERIFY_WORLD,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CLEAR_EXPLORATION,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SEND_MAIL,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSendMail                  );
    //OPCODE(SMSG_SEND_MAIL_RESULT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GET_MAIL_LIST,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetMailList               );
    //OPCODE(SMSG_MAIL_LIST_RESULT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_LIST,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldListOpcode     );
    //OPCODE(SMSG_BATTLEFIELD_LIST,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_JOIN,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCE_SET_VEHICLE_REC_ID,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_VEHICLE_REC_ID_ACK,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TAXICLEARNODE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_TAXIENABLENODE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ITEM_TEXT_QUERY,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemTextQuery             );
    //OPCODE(SMSG_ITEM_TEXT_QUERY_RESPONSE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MAIL_TAKE_MONEY,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeMoney             );
    //OPCODE(CMSG_MAIL_TAKE_ITEM,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailTakeItem              );
    //OPCODE(CMSG_MAIL_MARK_AS_READ,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailMarkAsRead            );
    //OPCODE(CMSG_MAIL_RETURN_TO_SENDER,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailReturnToSender        );
    //OPCODE(CMSG_MAIL_DELETE,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailDelete                );
    //OPCODE(CMSG_MAIL_CREATE_TEXT_ITEM,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleMailCreateTextItem        );
    //OPCODE(SMSG_SPELLLOGMISS,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLLOGEXECUTE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DEBUGAURAPROC,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PERIODICAURALOG,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLDAMAGESHIELD,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLNONMELEEDAMAGELOG,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LEARN_TALENT,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnTalentOpcode         );
    //OPCODE(SMSG_RESURRECT_FAILED,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TOGGLE_PVP,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTogglePvP                 );
    //OPCODE(SMSG_ZONE_UNDER_ATTACK,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_AUCTION_HELLO,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionHelloOpcode        );
    //OPCODE(CMSG_AUCTION_SELL_ITEM,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionSellItem           );
    //OPCODE(CMSG_AUCTION_REMOVE_ITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionRemoveItem         );
    //OPCODE(CMSG_AUCTION_LIST_ITEMS,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListItems          );
    //OPCODE(CMSG_AUCTION_LIST_OWNER_ITEMS,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListOwnerItems     );
    //OPCODE(CMSG_AUCTION_PLACE_BID,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionPlaceBid           );
    //OPCODE(SMSG_AUCTION_COMMAND_RESULT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AUCTION_LIST_RESULT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AUCTION_OWNER_LIST_RESULT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AUCTION_BIDDER_NOTIFICATION,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AUCTION_OWNER_NOTIFICATION,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PROCRESIST,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMBAT_EVENT_FAILED,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DISPEL_FAILED,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLORDAMAGE_IMMUNE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_AUCTION_LIST_BIDDER_ITEMS,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListBidderItems    );
    //OPCODE(SMSG_AUCTION_BIDDER_LIST_RESULT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_FLAT_SPELL_MODIFIER,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_PCT_SPELL_MODIFIER,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_AMMO,                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetAmmoOpcode             );
    //OPCODE(SMSG_CORPSE_RECLAIM_DELAY,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_ACTIVE_MOVER,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveMoverOpcode      );
    //OPCODE(CMSG_PET_CANCEL_AURA,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetCancelAuraOpcode       );
    //OPCODE(CMSG_PLAYER_AI_CHEAT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CANCEL_AUTO_REPEAT_SPELL,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelAutoRepeatSpellOpcode);
    //OPCODE(MSG_GM_ACCOUNT_ONLINE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_LIST_STABLED_PETS,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleListStabledPetsOpcode     );
    //OPCODE(CMSG_STABLE_PET,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStablePet                 );
    //OPCODE(CMSG_UNSTABLE_PET,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleUnstablePet               );
    //OPCODE(CMSG_BUY_STABLE_SLOT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuyStableSlot             );
    //OPCODE(SMSG_STABLE_RESULT,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_STABLE_REVIVE_PET,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableRevivePet           );
    //OPCODE(CMSG_STABLE_SWAP_PET,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleStableSwapPet             );
    //OPCODE(MSG_QUEST_PUSH_RESULT,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestPushResult           );
    //OPCODE(SMSG_PLAY_MUSIC,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PLAY_OBJECT_SOUND,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REQUEST_PET_INFO,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPetInfoOpcode      );
    //OPCODE(CMSG_FAR_SIGHT,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleFarSightOpcode            );
    //OPCODE(SMSG_SPELLDISPELLOG,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DAMAGE_CALC_LOG,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ENABLE_DAMAGE_LOG,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GROUP_CHANGE_SUB_GROUP,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupChangeSubGroupOpcode );
    //OPCODE(CMSG_REQUEST_PARTY_MEMBER_STATS,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestPartyMemberStatsOpcode);
    //OPCODE(CMSG_GROUP_SWAP_SUB_GROUP,                    STATUS_UNHANDLED, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_RESET_FACTION_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AUTOSTORE_BANK_ITEM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoStoreBankItemOpcode   );
    //OPCODE(CMSG_AUTOBANK_ITEM,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAutoBankItemOpcode        );
    //OPCODE(MSG_QUERY_NEXT_MAIL_TIME,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryNextMailTime         );
    //OPCODE(SMSG_RECEIVED_MAIL,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_RAID_GROUP_ONLY,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_DURABILITY_CHEAT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_PVP_RANK_CHEAT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ADD_PVP_MEDAL_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DEL_PVP_MEDAL_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_PVP_TITLE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PVP_CREDIT,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AUCTION_REMOVED_NOTIFICATION,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GROUP_RAID_CONVERT,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupRaidConvertOpcode    );
    //OPCODE(CMSG_GROUP_ASSISTANT_LEADER,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGroupAssistantLeaderOpcode);
    //OPCODE(CMSG_BUYBACK_ITEM,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBuybackItem               );
    //OPCODE(SMSG_SERVER_MESSAGE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_SAVED_INSTANCE_EXTEND,               STATUS_UNHANDLED, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LFG_OFFER_CONTINUE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TEST_DROP_RATE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_TEST_DROP_RATE_RESULT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LFG_GET_STATUS,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SHOW_MAILBOX,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_RESET_RANGED_COMBAT_TIMER,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHAT_NOT_IN_PARTY,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GMTICKETSYSTEM_TOGGLE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CANCEL_GROWTH_AURA,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelGrowthAuraOpcode    );
    //OPCODE(SMSG_CANCEL_AUTO_REPEAT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_STANDSTATE_UPDATE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_ALL_PASSED,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_ROLL_WON,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LOOT_ROLL,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootRoll                  );
    //OPCODE(SMSG_LOOT_START_ROLL,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_ROLL,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LOOT_MASTER_GIVE,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLootMasterGiveOpcode      );
    //OPCODE(SMSG_LOOT_MASTER_LIST,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_FORCED_REACTIONS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_FAILED_OTHER,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GAMEOBJECT_RESET_STATE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REPAIR_ITEM,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRepairItemOpcode          );
    //OPCODE(SMSG_CHAT_PLAYER_NOT_FOUND,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_TALENT_WIPE_CONFIRM,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTalentWipeConfirmOpcode   );
    //OPCODE(SMSG_SUMMON_REQUEST,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SUMMON_RESPONSE,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSummonResponseOpcode      );
    //OPCODE(MSG_DEV_SHOWLABEL,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_MONSTER_MOVE_TRANSPORT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_BROKEN,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_MOVE_FEATHER_FALL,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_WATER_WALK,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SERVER_BROADCAST,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SELF_RES,                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSelfResOpcode             );
    //OPCODE(SMSG_FEIGN_DEATH_RESISTED,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_RUN_SCRIPT,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SCRIPT_MESSAGE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DUEL_COUNTDOWN,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AREA_TRIGGER_MESSAGE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SHOWING_HELM,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingHelmOpcode         );
    //OPCODE(CMSG_SHOWING_CLOAK,                           STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleShowingCloakOpcode        );
    //OPCODE(SMSG_ROLE_CHOSEN,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PLAYER_SKINNED,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DURABILITY_DAMAGE_DEATH,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_EXPLORATION,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_ACTIONBAR_TOGGLES,                   STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActionBarTogglesOpcode );
    //OPCODE(UMSG_DELETE_GUILD_CHARTER,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_PETITION_RENAME,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetitionRenameOpcode      );
    //OPCODE(SMSG_INIT_WORLD_STATES,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_UPDATE_WORLD_STATE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ITEM_NAME_QUERY,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemNameQueryOpcode       );
    //OPCODE(SMSG_ITEM_NAME_QUERY_RESPONSE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_ACTION_FEEDBACK,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHAR_RENAME,                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharRenameOpcode          );
    //OPCODE(SMSG_CHAR_RENAME,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_SPLINE_DONE,                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSplineDoneOpcode      );
    //OPCODE(CMSG_MOVE_FALL_RESET,                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(SMSG_INSTANCE_SAVE_CREATED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_RAID_INSTANCE_INFO,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REQUEST_RAID_INFO,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRequestRaidInfoOpcode     );
    //OPCODE(CMSG_MOVE_TIME_SKIPPED,                       STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleMoveTimeSkippedOpcode     );
    //OPCODE(CMSG_MOVE_FEATHER_FALL_ACK,                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleFeatherFallAck            );
    //OPCODE(CMSG_MOVE_WATER_WALK_ACK,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveWaterWalkAck          );
    //OPCODE(CMSG_MOVE_NOT_ACTIVE_MOVER,                   STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveNotActiveMoverOpcode  );
    //OPCODE(SMSG_PLAY_SOUND,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_STATUS,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlefieldStatusOpcode   );
    //OPCODE(SMSG_BATTLEFIELD_STATUS,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_PORT,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattleFieldPortOpcode     );
    //OPCODE(MSG_INSPECT_HONOR_STATS,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectHonorStatsOpcode   );
    //OPCODE(CMSG_BATTLEMASTER_HELLO,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterHelloOpcode   );
    //OPCODE(CMSG_MOVE_START_SWIM_CHEAT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_MOVE_STOP_SWIM_CHEAT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCE_WALK_SPEED_CHANGE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_WALK_SPEED_CHANGE_ACK,             STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_FORCE_SWIM_BACK_SPEED_CHANGE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK,        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_FORCE_TURN_RATE_CHANGE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_TURN_RATE_CHANGE_ACK,              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(MSG_PVP_LOG_DATA,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePVPLogDataOpcode          );
    //OPCODE(CMSG_LEAVE_BATTLEFIELD,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLeaveBattlefieldOpcode    );
    //OPCODE(CMSG_AREA_SPIRIT_HEALER_QUERY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaSpiritHealerQueryOpcode);
    //OPCODE(CMSG_AREA_SPIRIT_HEALER_QUEUE,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAreaSpiritHealerQueueOpcode);
    //OPCODE(SMSG_AREA_SPIRIT_HEALER_TIME,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_UNTEACH,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_WARDEN_DATA,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_WARDEN_DATA,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleWardenDataOpcode          );
    //OPCODE(SMSG_GROUP_JOINED_BATTLEGROUND,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_BATTLEGROUND_PLAYER_POSITIONS,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattleGroundPlayerPositionsOpcode);
    //OPCODE(CMSG_PET_STOP_ATTACK,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetStopAttack             );
    //OPCODE(SMSG_BINDER_CONFIRM,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BATTLEGROUND_PLAYER_JOINED,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BATTLEGROUND_PLAYER_LEFT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEMASTER_JOIN,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinOpcode    );
    OPCODE(SMSG_ADDON_INFO,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PET_UNLEARN,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetUnlearnOpcode          );
    //OPCODE(SMSG_PET_UNLEARN_CONFIRM,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PARTY_MEMBER_STATS_FULL,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PET_SPELL_AUTOCAST,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetSpellAutocastOpcode    );
    //OPCODE(SMSG_WEATHER,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PLAY_TIME_WARNING,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MINIGAME_SETUP,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MINIGAME_STATE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MINIGAME_MOVE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_MINIGAME_MOVE_FAILED,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_RAID_INSTANCE_MESSAGE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMPRESSED_MOVES,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_INFO_TEXT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildChangeInfoTextOpcode );
    //OPCODE(SMSG_CHAT_RESTRICTED,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_RUN_SPEED,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_RUN_BACK_SPEED,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_SWIM_SPEED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_WALK_SPEED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_SWIM_BACK_SPEED,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_TURN_RATE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_UNROOT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_FEATHER_FALL,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_NORMAL_FALL,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_SET_HOVER,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_UNSET_HOVER,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_WATER_WALK,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_LAND_WALK,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_START_SWIM,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_STOP_SWIM,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_SET_RUN_MODE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_SET_WALK_MODE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_NUKE_ACCOUNT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_GM_DESTROY_CORPSE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_DESTROY_ONLINE_CORPSE,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ACTIVATETAXIEXPRESS,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleActivateTaxiExpressOpcode );
    //OPCODE(SMSG_SET_FACTION_ATWAR,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GAMETIMEBIAS_SET,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DEBUG_ACTIONS_START,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DEBUG_ACTIONS_STOP,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_FACTION_INACTIVE,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetFactionInactiveOpcode  );
    //OPCODE(CMSG_SET_WATCHED_FACTION,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetWatchedFactionOpcode   );
    //OPCODE(MSG_MOVE_TIME_SKIPPED,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SPLINE_MOVE_ROOT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_EXPLORATION_ALL,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_INVALIDATE_PLAYER,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_RESET_INSTANCES,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleResetInstancesOpcode      );
    //OPCODE(SMSG_INSTANCE_RESET,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_INSTANCE_RESET_FAILED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_UPDATE_LAST_INSTANCE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_RAID_TARGET_UPDATE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidTargetUpdateOpcode    );
    //OPCODE(MSG_RAID_READY_CHECK,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckOpcode      );
    //OPCODE(CMSG_LUA_USAGE,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PET_ACTION_SOUND,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_DISMISS_SOUND,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GHOSTEE_GONE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_UPDATE_TICKET_STATUS,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GM_TICKET_STATUS_UPDATE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_SET_DUNGEON_DIFFICULTY,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetDungeonDifficultyOpcode);
    //OPCODE(CMSG_GMSURVEY_SUBMIT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMSurveySubmitOpcode      );
    //OPCODE(SMSG_UPDATE_INSTANCE_OWNERSHIP,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_IGNORE_KNOCKBACK_CHEAT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CHAT_PLAYER_AMBIGUOUS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_DELAY_GHOST_TELEPORT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SPELLINSTAKILLLOG,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_UPDATE_CHAIN_TARGETS,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHAT_FILTERED,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_EXPECTED_SPAM_RECORDS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELLSTEALLOG,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LOTTERY_QUERY_OBSOLETE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LOTTERY_QUERY_RESULT_OBSOLETE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BUY_LOTTERY_TICKET_OBSOLETE,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LOTTERY_RESULT_OBSOLETE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHARACTER_PROFILE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHARACTER_PROFILE_REALM_CONNECTED,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DEFENSE_MESSAGE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_INSTANCE_DIFFICULTY,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_GM_RESETINSTANCELIMIT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    OPCODE(SMSG_MOTD,                                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY, STATUS_NEVER, PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_UNSET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY, STATUS_NEVER, PROCESS_INPLACE,    &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK, STATUS_NEVER, PROCESS_INPLACE,  &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_START_SWIM_CHEAT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_STOP_SWIM_CHEAT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_MOVE_SET_CAN_FLY,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_UNSET_CAN_FLY,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_SET_CAN_FLY_ACK,                    STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMoveSetCanFlyAckOpcode    );
    //OPCODE(CMSG_MOVE_SET_FLY,                            STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(CMSG_SOCKET_GEMS,                             STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSocketOpcode              );
    //OPCODE(CMSG_ARENA_TEAM_CREATE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_ARENA_TEAM_COMMAND_RESULT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_MOVE_UPDATE_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY, STATUS_NEVER, PROCESS_INPLACE,    &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ARENA_TEAM_QUERY,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamQueryOpcode      );
    //OPCODE(SMSG_ARENA_TEAM_QUERY_RESPONSE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ARENA_TEAM_ROSTER,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRosterOpcode     );
    //OPCODE(SMSG_ARENA_TEAM_ROSTER,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ARENA_TEAM_INVITE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamInviteOpcode     );
    //OPCODE(SMSG_ARENA_TEAM_INVITE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ARENA_TEAM_ACCEPT,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamAcceptOpcode     );
    //OPCODE(CMSG_ARENA_TEAM_DECLINE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDeclineOpcode    );
    //OPCODE(CMSG_ARENA_TEAM_LEAVE,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaveOpcode      );
    //OPCODE(CMSG_ARENA_TEAM_REMOVE,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamRemoveOpcode     );
    //OPCODE(CMSG_ARENA_TEAM_DISBAND,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamDisbandOpcode    );
    //OPCODE(CMSG_ARENA_TEAM_LEADER,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleArenaTeamLeaderOpcode     );
    //OPCODE(SMSG_ARENA_TEAM_EVENT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEMASTER_JOIN_ARENA,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleBattlemasterJoinArena     );
    //OPCODE(MSG_MOVE_START_ASCEND,                        STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_MOVE_STOP_ASCEND,                         STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(SMSG_ARENA_TEAM_STATS,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LFG_JOIN,                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgJoinOpcode             );
    //OPCODE(CMSG_LFG_LEAVE,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLfgLeaveOpcode            );
    //OPCODE(CMSG_LFG_SEARCH_JOIN,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSearchLfgJoinOpcode       );
    //OPCODE(CMSG_LFG_SEARCH_LEAVE,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSearchLfgLeaveOpcode      );
    //OPCODE(SMSG_LFG_SEARCH_RESULTS,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_PROPOSAL_UPDATE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LFG_PROPOSAL_RESPONSE,                   STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LFG_ROLE_CHECK_UPDATE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_JOIN_RESULT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_QUEUE_STATUS,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_LFG_COMMENT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetLfgCommentOpcode       );
    //OPCODE(SMSG_LFG_UPDATE_PLAYER,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_UPDATE_PARTY,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_UPDATE_SEARCH,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LFG_SET_ROLES,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_LFG_SET_NEEDS,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_LFG_BOOT_PLAYER_VOTE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LFG_BOOT_PLAYER,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LFG_GET_PLAYER_INFO,                     STATUS_UNHANDLED, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LFG_PLAYER_INFO,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LFG_TELEPORT,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_LFG_GET_PARTY_INFO,                      STATUS_UNHANDLED, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_LFG_PARTY_INFO,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TITLE_EARNED,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_TITLE,                               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetTitleOpcode            );
    //OPCODE(CMSG_CANCEL_MOUNT_AURA,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelMountAuraOpcode     );
    //OPCODE(SMSG_ARENA_ERROR,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_INSPECT_ARENA_TEAMS,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleInspectArenaTeamsOpcode   );
    //OPCODE(SMSG_DEATH_RELEASE_LOC,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CANCEL_TEMP_ENCHANTMENT,                 STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCancelTempEnchantmentOpcode);
    //OPCODE(SMSG_FORCED_DEATH_UPDATE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHEAT_SET_HONOR_CURRENCY,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHEAT_SET_ARENA_CURRENCY,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_FLIGHT_SPEED_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_FLIGHT_SPEED,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_FLIGHT_BACK_SPEED,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCE_FLIGHT_SPEED_CHANGE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK,           STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK,      STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleForceSpeedChangeAckOpcodes);
    //OPCODE(SMSG_SPLINE_SET_FLIGHT_SPEED,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_SET_FLIGHT_BACK_SPEED,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MAELSTROM_INVALIDATE_CACHE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FLIGHT_SPLINE_SYNC,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_TAXI_BENCHMARK_MODE,                 STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetTaxiBenchmarkOpcode    );
    //OPCODE(SMSG_JOINED_BATTLEGROUND_QUEUE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_REALM_SPLIT,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REALM_SPLIT,                             STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleRealmSplitOpcode          );
    //OPCODE(CMSG_MOVE_CHNG_TRANSPORT,                     STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(MSG_PARTY_ASSIGNMENT,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePartyAssignmentOpcode     );
    //OPCODE(SMSG_OFFER_PETITION_ERROR,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_TIME_SYNC_REQ,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TIME_SYNC_RESP,                          STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleTimeSyncResp              );
    //OPCODE(CMSG_SEND_LOCAL_EVENT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SEND_GENERAL_TRIGGER,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SEND_COMBAT_TRIGGER,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_MAELSTROM_GM_SENT_MAIL,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_RESET_FAILED_NOTIFY,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_REAL_GROUP_UPDATE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LFG_DISABLED,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ACTIVE_PVP_CHEAT,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE,    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE_WRITE_FILE, STATUS_NEVER, PROCESS_INPLACE,      &WorldSession::Handle_ServerSide            );
    //OPCODE(SMSG_UPDATE_COMBO_POINTS,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_VOICE_SESSION_ROSTER_UPDATE,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_VOICE_SESSION_LEAVE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_VOICE_SESSION_ADJUST_PRIORITY,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_VOICE_SET_TALKER_MUTED_REQUEST,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_VOICE_SET_TALKER_MUTED,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_INIT_EXTRA_AURA_INFO_OBSOLETE,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_EXTRA_AURA_INFO_OBSOLETE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_EXTRA_AURA_INFO_NEED_UPDATE_OBSOLETE, STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CLEAR_EXTRA_AURA_INFO_OBSOLETE,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_MOVE_START_DESCEND,                       STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleMovementOpcodes           );
    //OPCODE(CMSG_IGNORE_REQUIREMENTS_CHEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_IGNORE_REQUIREMENTS_CHEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_CHANCE_PROC_LOG,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_SET_RUN_SPEED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DISMOUNT,                                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_MOVE_UPDATE_CAN_FLY,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_RAID_READY_CHECK_CONFIRM,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_VOICE_SESSION_ENABLE,                    STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleVoiceSessionEnableOpcode  );
    //OPCODE(SMSG_VOICE_SESSION_ENABLE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_VOICE_PARENTAL_CONTROLS,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_WHISPER,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GM_MESSAGECHAT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_GM_GEARRATING,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_COMMENTATOR_ENABLE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_COMMENTATOR_STATE_CHANGED,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_COMMENTATOR_GET_MAP_INFO,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_COMMENTATOR_MAP_INFO,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_COMMENTATOR_GET_PLAYER_INFO,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_COMMENTATOR_GET_PLAYER_INFO,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMMENTATOR_PLAYER_INFO,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_COMMENTATOR_ENTER_INSTANCE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_COMMENTATOR_EXIT_INSTANCE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_COMMENTATOR_INSTANCE_COMMAND,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CLEAR_TARGET,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BOT_DETECTED,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CROSSED_INEBRIATION_THRESHOLD,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHEAT_PLAYER_LOGIN,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHEAT_PLAYER_LOOKUP,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CHEAT_PLAYER_LOOKUP,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_KICK_REASON,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_RAID_READY_CHECK_FINISHED,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRaidReadyCheckFinishedOpcode);
    //OPCODE(CMSG_COMPLAIN,                                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleComplainOpcode            );
    //OPCODE(SMSG_COMPLAIN_RESULT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_FEATURE_SYSTEM_STATUS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_SHOW_COMPLAINTS,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_UNSQUELCH,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHANNEL_SILENCE_VOICE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHANNEL_SILENCE_ALL,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHANNEL_UNSILENCE_VOICE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHANNEL_UNSILENCE_ALL,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_TARGET_CAST,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_TARGET_SCRIPT_CAST,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHANNEL_DISPLAY_LIST,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelDisplayListQueryOpcode);
    //OPCODE(CMSG_SET_ACTIVE_VOICE_CHANNEL,                STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetActiveVoiceChannel     );
    //OPCODE(CMSG_GET_CHANNEL_MEMBER_COUNT,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGetChannelMemberCountOpcode);
    //OPCODE(SMSG_CHANNEL_MEMBER_COUNT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANNEL_VOICE_ON,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleChannelVoiceOnOpcode      );
    //OPCODE(CMSG_CHANNEL_VOICE_OFF,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DEBUG_LIST_TARGETS,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DEBUG_LIST_TARGETS,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AVAILABLE_VOICE_CHANNEL,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ADD_VOICE_IGNORE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DEL_VOICE_IGNORE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_PARTY_SILENCE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_PARTY_UNSILENCE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_NOTIFY_PARTY_SQUELCH,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_COMSAT_RECONNECT_TRY,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMSAT_DISCONNECT,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMSAT_CONNECT_FAIL,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_VOICE_CHAT_STATUS,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REPORT_PVP_AFK,                          STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleReportPvPAFK              );
    //OPCODE(SMSG_REPORT_PVP_AFK_RESULT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GUILD_BANKER_ACTIVATE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankerActivate       );
    //OPCODE(CMSG_GUILD_BANK_QUERY_TAB,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankQueryTab         );
    //OPCODE(SMSG_GUILD_BANK_LIST,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GUILD_BANK_SWAP_ITEMS,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankSwapItems        );
    //OPCODE(CMSG_GUILD_BANK_BUY_TAB,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankBuyTab           );
    //OPCODE(CMSG_GUILD_BANK_UPDATE_TAB,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankUpdateTab        );
    //OPCODE(CMSG_GUILD_BANK_DEPOSIT_MONEY,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankDepositMoney     );
    //OPCODE(CMSG_GUILD_BANK_WITHDRAW_MONEY,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankWithdrawMoney    );
    //OPCODE(MSG_GUILD_BANK_LOG_QUERY,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankLogQuery         );
    //OPCODE(CMSG_SET_CHANNEL_WATCH,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetChannelWatchOpcode     );
    //OPCODE(SMSG_USERLIST_ADD,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_USERLIST_REMOVE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_USERLIST_UPDATE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CLEAR_CHANNEL_WATCH,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_INSPECT_RESULTS,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GOGOGO_OBSOLETE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ECHO_PARTY_SQUELCH,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_TITLE_SUFFIX,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SPELLCLICK,                              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSpellClick                );
    //OPCODE(SMSG_LOOT_LIST,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_CHARACTER_RESTORE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_CHARACTER_SAVE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_VOICESESSION_FULL,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(MSG_GUILD_PERMISSIONS,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildPermissions          );
    //OPCODE(MSG_GUILD_BANK_MONEY_WITHDRAWN,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildBankMoneyWithdrawn   );
    //OPCODE(MSG_GUILD_EVENT_LOG_QUERY,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGuildEventLogQueryOpcode  );
    //OPCODE(CMSG_MAELSTROM_RENAME_GUILD,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GET_MIRRORIMAGE_DATA,                    STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleGetMirrorimageData        );
    //OPCODE(SMSG_MIRRORIMAGE_DATA,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_FORCE_DISPLAY_UPDATE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPELL_CHANCE_RESIST_PUSHBACK,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_KEEP_ALIVE,                              STATUS_NEVER,    PROCESS_THREADUNSAFE, &WorldSession::Handle_EarlyProccess            );
    //OPCODE(SMSG_RAID_READY_CHECK_ERROR,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_OPT_OUT_OF_LOOT,                         STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleOptOutOfLootOpcode        );
    //OPCODE(MSG_QUERY_GUILD_BANK_TEXT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryGuildBankTabText     );
    //OPCODE(CMSG_SET_GUILD_BANK_TEXT,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetGuildBankTabText       );
    //OPCODE(CMSG_SET_GRANTABLE_LEVELS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GRANT_LEVEL,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_REFER_A_FRIEND,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_GM_CHANGE_ARENA_RATING,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DECLINE_CHANNEL_INVITE,                  STATUS_UNHANDLED, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_GROUPACTION_THROTTLED,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_OVERRIDE_LIGHT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TOTEM_CREATED,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_TOTEM_DESTROYED,                         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleTotemDestroyed            );
    //OPCODE(CMSG_EXPIRE_RAID_INSTANCE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_NO_SPELL_VARIANCE,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY,        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQuestgiverStatusMultipleQuery);
    //OPCODE(SMSG_QUESTGIVER_STATUS_MULTIPLE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_PLAYER_DECLINED_NAMES,               STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleSetPlayerDeclinedNamesOpcode);
    //OPCODE(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUERY_SERVER_BUCK_DATA,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CLEAR_SERVER_BUCK_DATA,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SERVER_BUCK_DATA,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_SEND_UNLEARN_SPELLS,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PROPOSE_LEVEL_GRANT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ACCEPT_LEVEL_GRANT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_REFER_A_FRIEND_FAILURE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_SET_FLYING,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_UNSET_FLYING,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SUMMON_CANCEL,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANGE_PERSONAL_ARENA_RATING,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_ALTER_APPEARANCE,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAlterAppearanceOpcode     );
    //OPCODE(SMSG_ENABLE_BARBER_SHOP,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BARBER_SHOP_RESULT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CALENDAR_GET_CALENDAR,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetCalendar       );
    //OPCODE(CMSG_CALENDAR_GET_EVENT,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetEvent          );
    //OPCODE(CMSG_CALENDAR_GUILD_FILTER,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGuildFilter       );
    //OPCODE(CMSG_CALENDAR_ARENA_TEAM,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarArenaTeam         );
    //OPCODE(CMSG_CALENDAR_ADD_EVENT,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarAddEvent          );
    //OPCODE(CMSG_CALENDAR_UPDATE_EVENT,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarUpdateEvent       );
    //OPCODE(CMSG_CALENDAR_REMOVE_EVENT,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarRemoveEvent       );
    //OPCODE(CMSG_CALENDAR_COPY_EVENT,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarCopyEvent         );
    //OPCODE(CMSG_CALENDAR_EVENT_INVITE,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventInvite       );
    //OPCODE(CMSG_CALENDAR_EVENT_RSVP,                     STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRsvp         );
    //OPCODE(CMSG_CALENDAR_EVENT_REMOVE_INVITE,            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventRemoveInvite );
    //OPCODE(CMSG_CALENDAR_EVENT_STATUS,                   STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventStatus       );
    //OPCODE(CMSG_CALENDAR_EVENT_MODERATOR_STATUS,         STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarEventModeratorStatus);
    //OPCODE(SMSG_CALENDAR_SEND_CALENDAR,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_SEND_EVENT,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_FILTER_GUILD,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_ARENA_TEAM,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE_REMOVED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_STATUS,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_COMMAND_RESULT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_ADDED,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_REMOVED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE_ALERT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_REMOVED_ALERT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_UPDATED_ALERT,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_MODERATOR_STATUS_ALERT,   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CALENDAR_COMPLAIN,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarComplain          );
    //OPCODE(CMSG_CALENDAR_GET_NUM_PENDING,                STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCalendarGetNumPending     );
    //OPCODE(SMSG_CALENDAR_SEND_NUM_PENDING,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SAVE_DANCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_NOTIFY_DANCE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PLAY_DANCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PLAY_DANCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LOAD_DANCES,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_STOP_DANCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_STOP_DANCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SYNC_DANCE,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DANCE_QUERY,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DANCE_QUERY_RESPONSE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_INVALIDATE_DANCE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DELETE_DANCE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    OPCODE(SMSG_LEARNED_DANCE_MOVES,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LEARN_DANCE_MOVE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_UNLEARN_DANCE_MOVE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_RUNE_COUNT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_RUNE_COOLDOWN,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_PITCH_RATE_CHEAT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_PITCH_RATE,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCE_PITCH_RATE_CHANGE,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_PITCH_RATE_CHANGE_ACK,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SPLINE_SET_PITCH_RATE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CALENDAR_EVENT_INVITE_NOTES,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE_NOTES,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_UPDATE_MISSILE_TRAJECTORY,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_UPDATE_ACCOUNT_DATA_COMPLETE,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TRIGGER_MOVIE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_COMPLETE_MOVIE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_GLYPH_SLOT,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_GLYPH,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_ACHIEVEMENT_EARNED,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_DYNAMIC_DROP_ROLL_RESULT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CRITERIA_UPDATE,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_QUERY_INSPECT_ACHIEVEMENTS,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryInspectAchievementsOpcode);
    //OPCODE(SMSG_RESPOND_INSPECT_ACHIEVEMENTS,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DISMISS_CONTROLLED_VEHICLE,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleDismissControlledVehicle  );
    //OPCODE(CMSG_COMPLETE_ACHIEVEMENT_CHEAT,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_QUESTUPDATE_ADD_PVP_KILL,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_CRITERIA_CHEAT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CALENDAR_RAID_LOCKOUT_UPDATED,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_UNITANIMTIER_CHEAT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CHAR_CUSTOMIZE,                          STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleCharCustomizeOpcode       );
    //OPCODE(SMSG_CHAR_CUSTOMIZE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_RENAMEABLE,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_REQUEST_VEHICLE_EXIT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_REQUEST_VEHICLE_PREV_SEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_REQUEST_VEHICLE_NEXT_SEAT,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_REQUEST_VEHICLE_SWITCH_SEAT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_PET_LEARN_TALENT,                        STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandlePetLearnTalent            );
    //OPCODE(CMSG_PET_UNLEARN_TALENTS,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SET_PHASE_SHIFT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ALL_ACHIEVEMENT_DATA,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_SAY_CHEAT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_HEALTH_UPDATE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_POWER_UPDATE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GAMEOBJ_REPORT_USE,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGameobjectReportUse       );
    //OPCODE(SMSG_HIGHEST_THREAT_UPDATE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_THREAT_UPDATE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_THREAT_REMOVE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_THREAT_CLEAR,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CONVERT_RUNE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_RESYNC_RUNES,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ADD_RUNE_POWER,                          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_START_QUEST,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_REMOVE_GLYPH,                            STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleRemoveGlyphOpcode         );
    //OPCODE(CMSG_DUMP_OBJECTS,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DUMP_OBJECTS_DATA,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DISMISS_CRITTER,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_NOTIFY_DEST_LOC_SPELL_CAST,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_AUCTION_LIST_PENDING_SALES,              STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleAuctionListPendingSales   );
    //OPCODE(SMSG_AUCTION_LIST_PENDING_SALES,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MODIFY_COOLDOWN,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_UPDATE_COMBO_POINTS,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_ENABLETAXI,                              STATUS_LOGGEDIN, PROCESS_THREADSAFE,   &WorldSession::HandleTaxiQueryAvailableNodes   );
    //OPCODE(SMSG_PRE_RESURRECT,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AURA_UPDATE_ALL,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_AURA_UPDATE,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FLOOD_GRACE_CHEAT,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SERVER_FIRST_ACHIEVEMENT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_LEARNED_SPELL,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_PET_REMOVED_SPELL,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANGE_SEATS_ON_CONTROLLED_VEHICLE,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_HEARTH_AND_RESURRECT,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleHearthandResurrect        );
    //OPCODE(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA,    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_CRITERIA_DELETED,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ACHIEVEMENT_DELETED,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SERVER_INFO_QUERY,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SERVER_INFO_RESPONSE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHECK_LOGIN_CRITERIA,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SERVER_BUCK_DATA_START,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_BREATH,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_QUERY_VEHICLE_STATUS,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_BATTLEGROUND_INFO_THROTTLED,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SET_VEHICLE_REC_ID,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_RIDE_VEHICLE_INTERACT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CONTROLLER_EJECT_PASSENGER,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PET_GUIDS,                               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    OPCODE(SMSG_CLIENTCACHE_VERSION,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHANGE_GDF_ARENA_RATING,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_ARENA_TEAM_RATING_BY_INDEX,          STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_ARENA_TEAM_WEEKLY_GAMES,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_ARENA_TEAM_SEASON_GAMES,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_ARENA_MEMBER_WEEKLY_GAMES,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_ARENA_MEMBER_SEASON_GAMES,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SET_ITEM_PURCHASE_DATA,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GET_ITEM_PURCHASE_DATA,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleItemRefundInfoRequest     );
    //OPCODE(CMSG_ITEM_PURCHASE_REFUND,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_ITEM_PURCHASE_REFUND_RESULT,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CORPSE_TRANSPORT_QUERY,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleCorpseMapPositionQueryOpcode);
    //OPCODE(SMSG_CORPSE_TRANSPORT_QUERY,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_UNUSED5,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_UNUSED6,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CALENDAR_EVENT_SIGNUP,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CALENDAR_CLEAR_PENDING_ACTION,           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOAD_EQUIPMENT_SET,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SAVE_EQUIPMENT_SET,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetSaveOpcode    );
    //OPCODE(CMSG_ON_MISSILE_TRAJECTORY_COLLISION,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_NOTIFY_MISSILE_TRAJECTORY_COLLISION,     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_TALENT_UPDATE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_LEARN_TALENT_GROUP,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalents       );
    //OPCODE(CMSG_PET_LEARN_TALENT_GROUP,                  STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleLearnPreviewTalentsPet    );
    //OPCODE(CMSG_SET_ACTIVE_TALENT_GROUP_OBSOLETE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_GRANT_ACHIEVEMENT,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_REMOVE_ACHIEVEMENT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_SET_CRITERIA_FOR_PLAYER,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DESTROY_ARENA_UNIT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_ARENA_TEAM_CHANGE_FAILED,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PROFILEDATA_REQUEST,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PROFILEDATA_RESPONSE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_START_BATTLEFIELD_CHEAT,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_END_BATTLEFIELD_CHEAT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_COMPOUND_MOVE,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_GRAVITY_DISABLE,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_GRAVITY_DISABLE_ACK,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_MOVE_GRAVITY_ENABLE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_GRAVITY_ENABLE_ACK,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_GRAVITY_CHNG,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_GRAVITY_DISABLE,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SPLINE_MOVE_GRAVITY_ENABLE,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_USE_EQUIPMENT_SET,                       STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleEquipmentSetUseOpcode     );
    //OPCODE(SMSG_USE_EQUIPMENT_SET_RESULT,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_FORCE_ANIM,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_FORCE_ANIM,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHAR_FACTION_CHANGE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CHAR_FACTION_CHANGE,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_PVP_QUEUE_STATS_REQUEST,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_PVP_QUEUE_STATS,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SET_PAID_SERVICE_CHEAT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_ENTRY_INVITE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_MANAGER_ENTRY_INVITE_RESPONSE, STATUS_NEVER,   PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_ENTERING,            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_QUEUE_INVITE,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_MANAGER_QUEUE_INVITE_RESPONSE, STATUS_NEVER,   PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_BATTLEFIELD_MANAGER_QUEUE_REQUEST,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_QUEUE_REQUEST_RESPONSE, STATUS_NEVER,  PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_EJECT_PENDING,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_EJECTED,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_MANAGER_EXIT_REQUEST,        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_BATTLEFIELD_MANAGER_STATE_CHANGED,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_BATTLEFIELD_MANAGER_ADVANCE_STATE,       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_BATTLEFIELD_MANAGER_SET_NEXT_TRANSITION_TIME, STATUS_NEVER, PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_SET_RAID_DIFFICULTY,                      STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleSetRaidDifficultyOpcode   );
    //OPCODE(CMSG_XPGAIN,                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_XPGAIN,                                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GMTICKET_RESPONSE_ERROR,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GMTICKET_GET_RESPONSE,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GMTICKET_RESOLVE_RESPONSE,               STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleGMResponseResolveOpcode   );
    //OPCODE(SMSG_GMTICKET_RESOLVE_RESPONSE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_GMTICKET_CREATE_RESPONSE_TICKET,         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_GM_CREATE_TICKET_RESPONSE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_SERVERINFO,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SERVERINFO,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_UI_TIME_REQUEST,                         STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleUITimeRequestOpcode       );
    //OPCODE(SMSG_UI_TIME,                                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CHAR_RACE_CHANGE,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_VIEW_PHASE_SHIFT,                         STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_TALENTS_INVOLUNTARILY_RESET,             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_DEBUG_SERVER_GEO,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_DEBUG_SERVER_GEO,                        STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_LOOT_UPDATE,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(UMSG_UPDATE_GROUP_INFO,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    OPCODE(CMSG_READY_FOR_ACCOUNT_DATA_TIMES,            STATUS_AUTHED,   PROCESS_THREADUNSAFE, &WorldSession::HandleReadyForAccountDataTimesOpcode);
    //OPCODE(CMSG_QUERY_GET_ALL_QUESTS,                    STATUS_LOGGEDIN, PROCESS_THREADUNSAFE, &WorldSession::HandleQueryQuestsCompletedOpcode);
    //OPCODE(SMSG_ALL_QUESTS_COMPLETED,                    STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GMLAGREPORT_SUBMIT,                      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AFK_MONITOR_INFO_REQUEST,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_AFK_MONITOR_INFO_RESPONSE,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_AFK_MONITOR_INFO_CLEAR,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_AREA_TRIGGER_NO_CORPSE,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_GM_NUKE_CHARACTER,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_LOW_LEVEL_RAID,                          STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetAllowLowLevelRaidOpcode);
    //OPCODE(CMSG_LOW_LEVEL_RAID_USER,                     STATUS_LOGGEDIN, PROCESS_INPLACE,      &WorldSession::HandleSetAllowLowLevelRaidOpcode);
    //OPCODE(SMSG_CAMERA_SHAKE,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_SOCKET_GEMS,                             STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SET_CHARACTER_MODEL,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_CONNECT_TO,                              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CONNECT_TO_FAILED,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SUSPEND_COMMS,                           STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_SUSPEND_COMMS_ACK,                       STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_RESUME_COMMS,                            STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_AUTH_CONTINUED_SESSION,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_DROP_NEW_CONNECTION,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_SEND_ALL_COMBAT_LOG,                     STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_OPEN_LFG_DUNGEON_FINDER,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_MOVE_SET_COLLISION_HGT,                  STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_MOVE_SET_COLLISION_HGT_ACK,              STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(MSG_MOVE_SET_COLLISION_HGT,                   STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(CMSG_CLEAR_RANDOM_BG_WIN_TIME,                STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_CLEAR_HOLIDAY_BG_WIN_TIME,               STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(CMSG_COMMENTATOR_SKIRMISH_QUEUE_COMMAND,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_NULL                     );
    //OPCODE(SMSG_COMMENTATOR_SKIRMISH_QUEUE_RESULT1,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMMENTATOR_SKIRMISH_QUEUE_RESULT2,      STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
    //OPCODE(SMSG_COMPRESSED_UNKNOWN_1310,                 STATUS_NEVER,    PROCESS_INPLACE,      &WorldSession::Handle_ServerSide               );
>>>>>>> 4ad0aac... Fix CMSG_CHAR_ENUM
};
