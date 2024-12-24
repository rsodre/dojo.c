#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum BlockTag {
  Latest,
  Pending,
} BlockTag;

typedef enum ComparisonOperator {
  Eq,
  Neq,
  Gt,
  Gte,
  Lt,
  Lte,
  In,
  NotIn,
} ComparisonOperator;

typedef enum LogicalOperator {
  And,
  Or,
} LogicalOperator;

typedef enum OrderDirection {
  Asc,
  Desc,
} OrderDirection;

typedef enum PatternMatching {
  FixedLen = 0,
  VariableLen = 1,
} PatternMatching;

typedef struct Account Account;

typedef struct Provider Provider;

typedef struct Subscription Subscription;

typedef struct ToriiClient ToriiClient;

typedef struct Error {
  char *message;
} Error;

typedef enum ResultToriiClient_Tag {
  OkToriiClient,
  ErrToriiClient,
} ResultToriiClient_Tag;

typedef struct ResultToriiClient {
  ResultToriiClient_Tag tag;
  union {
    struct {
      struct ToriiClient *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultToriiClient;

typedef struct FieldElement {
  uint8_t data[32];
} FieldElement;

typedef struct CArrayu8 {
  uint8_t *data;
  uintptr_t data_len;
} CArrayu8;

typedef enum ResultCArrayu8_Tag {
  OkCArrayu8,
  ErrCArrayu8,
} ResultCArrayu8_Tag;

typedef struct ResultCArrayu8 {
  ResultCArrayu8_Tag tag;
  union {
    struct {
      struct CArrayu8 ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCArrayu8;

typedef enum Primitive_Tag {
  I8,
  I16,
  I32,
  I64,
  I128,
  U8,
  U16,
  U32,
  U64,
  U128,
  U256,
#if defined(TARGET_POINTER_WIDTH_32)
  U256,
#endif
  USize,
  Bool,
  Felt252,
  ClassHash,
  ContractAddress,
} Primitive_Tag;

typedef struct Primitive {
  Primitive_Tag tag;
  union {
    struct {
      int8_t i8;
    };
    struct {
      int16_t i16;
    };
    struct {
      int32_t i32;
    };
    struct {
      int64_t i64;
    };
    struct {
      uint8_t i128[16];
    };
    struct {
      uint8_t u8;
    };
    struct {
      uint16_t u16;
    };
    struct {
      uint32_t u32;
    };
    struct {
      uint64_t u64;
    };
    struct {
      uint8_t u128[16];
    };
    struct {
      uint64_t u256[4];
    };
#if defined(TARGET_POINTER_WIDTH_32)
    struct {
      uint32_t u256[8];
    };
#endif
    struct {
      uint32_t u_size;
    };
    struct {
      bool bool_;
    };
    struct {
      struct FieldElement felt252;
    };
    struct {
      struct FieldElement class_hash;
    };
    struct {
      struct FieldElement contract_address;
    };
  };
} Primitive;

typedef struct EnumOption {
  const char *name;
  struct Ty *ty;
} EnumOption;

typedef struct CArrayEnumOption {
  struct EnumOption *data;
  uintptr_t data_len;
} CArrayEnumOption;

typedef struct Enum {
  const char *name;
  uint8_t option;
  struct CArrayEnumOption options;
} Enum;

typedef struct CArrayTy {
  struct Ty *data;
  uintptr_t data_len;
} CArrayTy;

typedef enum Ty_Tag {
  Primitive_,
  Struct_,
  Enum_,
  Tuple_,
  Array_,
  ByteArray,
} Ty_Tag;

typedef struct Ty {
  Ty_Tag tag;
  union {
    struct {
      struct Primitive primitive;
    };
    struct {
      struct Struct struct_;
    };
    struct {
      struct Enum enum_;
    };
    struct {
      struct CArrayTy tuple;
    };
    struct {
      struct CArrayTy array;
    };
    struct {
      const char *byte_array;
    };
  };
} Ty;

typedef struct Member {
  const char *name;
  struct Ty *ty;
  bool key;
} Member;

typedef struct CArrayMember {
  struct Member *data;
  uintptr_t data_len;
} CArrayMember;

typedef struct Struct {
  const char *name;
  struct CArrayMember children;
} Struct;

typedef struct CArrayStruct {
  struct Struct *data;
  uintptr_t data_len;
} CArrayStruct;

typedef struct Entity {
  struct FieldElement hashed_keys;
  struct CArrayStruct models;
} Entity;

typedef struct CArrayEntity {
  struct Entity *data;
  uintptr_t data_len;
} CArrayEntity;

typedef enum ResultCArrayEntity_Tag {
  OkCArrayEntity,
  ErrCArrayEntity,
} ResultCArrayEntity_Tag;

typedef struct ResultCArrayEntity {
  ResultCArrayEntity_Tag tag;
  union {
    struct {
      struct CArrayEntity ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCArrayEntity;

typedef enum COptionFieldElement_Tag {
  SomeFieldElement,
  NoneFieldElement,
} COptionFieldElement_Tag;

typedef struct COptionFieldElement {
  COptionFieldElement_Tag tag;
  union {
    struct {
      struct FieldElement some;
    };
  };
} COptionFieldElement;

typedef struct CArrayCOptionFieldElement {
  struct COptionFieldElement *data;
  uintptr_t data_len;
} CArrayCOptionFieldElement;

typedef struct CArrayc_char {
  const char **data;
  uintptr_t data_len;
} CArrayc_char;

typedef struct KeysClause {
  struct CArrayCOptionFieldElement keys;
  enum PatternMatching pattern_matching;
  struct CArrayc_char models;
} KeysClause;

typedef struct CArrayMemberValue {
  struct MemberValue *data;
  uintptr_t data_len;
} CArrayMemberValue;

typedef enum MemberValue_Tag {
  Primitive,
  String,
  List,
} MemberValue_Tag;

typedef struct MemberValue {
  MemberValue_Tag tag;
  union {
    struct {
      struct Primitive primitive;
    };
    struct {
      const char *string;
    };
    struct {
      struct CArrayMemberValue list;
    };
  };
} MemberValue;

typedef struct MemberClause {
  const char *model;
  const char *member;
  enum ComparisonOperator operator_;
  struct MemberValue value;
} MemberClause;

typedef struct CArrayClause {
  struct Clause *data;
  uintptr_t data_len;
} CArrayClause;

typedef struct CompositeClause {
  enum LogicalOperator operator_;
  struct CArrayClause clauses;
} CompositeClause;

typedef enum Clause_Tag {
  Keys,
  CMember,
  Composite,
} Clause_Tag;

typedef struct Clause {
  Clause_Tag tag;
  union {
    struct {
      struct KeysClause keys;
    };
    struct {
      struct MemberClause c_member;
    };
    struct {
      struct CompositeClause composite;
    };
  };
} Clause;

typedef enum COptionClause_Tag {
  SomeClause,
  NoneClause,
} COptionClause_Tag;

typedef struct COptionClause {
  COptionClause_Tag tag;
  union {
    struct {
      struct Clause some;
    };
  };
} COptionClause;

typedef struct OrderBy {
  const char *model;
  const char *member;
  enum OrderDirection direction;
} OrderBy;

typedef struct CArrayOrderBy {
  struct OrderBy *data;
  uintptr_t data_len;
} CArrayOrderBy;

typedef struct Query {
  uint32_t limit;
  uint32_t offset;
  struct COptionClause clause;
  bool dont_include_hashed_keys;
  struct CArrayOrderBy order_by;
  struct CArrayc_char entity_models;
  uint64_t entity_updated_after;
} Query;

typedef struct CArrayFieldElement {
  struct FieldElement *data;
  uintptr_t data_len;
} CArrayFieldElement;

typedef struct ModelMetadata {
  struct Ty schema;
  const char *namespace_;
  const char *name;
  uint32_t packed_size;
  uint32_t unpacked_size;
  struct FieldElement class_hash;
  struct FieldElement contract_address;
  struct CArrayFieldElement layout;
} ModelMetadata;

typedef struct CHashItemFieldElementModelMetadata {
  struct FieldElement key;
  struct ModelMetadata value;
} CHashItemFieldElementModelMetadata;

typedef struct CArrayCHashItemFieldElementModelMetadata {
  struct CHashItemFieldElementModelMetadata *data;
  uintptr_t data_len;
} CArrayCHashItemFieldElementModelMetadata;

typedef struct WorldMetadata {
  struct FieldElement world_address;
  struct CArrayCHashItemFieldElementModelMetadata models;
} WorldMetadata;

typedef enum ResultSubscription_Tag {
  OkSubscription,
  ErrSubscription,
} ResultSubscription_Tag;

typedef struct ResultSubscription {
  ResultSubscription_Tag tag;
  union {
    struct {
      struct Subscription *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultSubscription;

typedef enum EntityKeysClause_Tag {
  HashedKeys,
  EntityKeys,
} EntityKeysClause_Tag;

typedef struct EntityKeysClause {
  EntityKeysClause_Tag tag;
  union {
    struct {
      struct CArrayFieldElement hashed_keys;
    };
    struct {
      struct KeysClause entity_keys;
    };
  };
} EntityKeysClause;

typedef enum Resultbool_Tag {
  Okbool,
  Errbool,
} Resultbool_Tag;

typedef struct Resultbool {
  Resultbool_Tag tag;
  union {
    struct {
      bool ok;
    };
    struct {
      struct Error err;
    };
  };
} Resultbool;

typedef struct Event {
  struct CArrayFieldElement keys;
  struct CArrayFieldElement data;
  struct FieldElement transaction_hash;
} Event;

typedef struct Token {
  struct FieldElement contract_address;
  const char *name;
  const char *symbol;
  uint8_t decimals;
  const char *metadata;
} Token;

typedef struct CArrayToken {
  struct Token *data;
  uintptr_t data_len;
} CArrayToken;

typedef enum ResultCArrayToken_Tag {
  OkCArrayToken,
  ErrCArrayToken,
} ResultCArrayToken_Tag;

typedef struct ResultCArrayToken {
  ResultCArrayToken_Tag tag;
  union {
    struct {
      struct CArrayToken ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCArrayToken;

typedef struct TokenBalance {
  uint64_t balance[4];
#if defined(TARGET_POINTER_WIDTH_32)
  uint32_t balance[8]
#endif
  ;
  struct FieldElement account_address;
  struct FieldElement contract_address;
  const char *token_id;
} TokenBalance;

typedef struct CArrayTokenBalance {
  struct TokenBalance *data;
  uintptr_t data_len;
} CArrayTokenBalance;

typedef enum ResultCArrayTokenBalance_Tag {
  OkCArrayTokenBalance,
  ErrCArrayTokenBalance,
} ResultCArrayTokenBalance_Tag;

typedef struct ResultCArrayTokenBalance {
  ResultCArrayTokenBalance_Tag tag;
  union {
    struct {
      struct CArrayTokenBalance ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCArrayTokenBalance;

typedef struct IndexerUpdate {
  int64_t head;
  int64_t tps;
  int64_t last_block_timestamp;
  struct FieldElement contract_address;
} IndexerUpdate;

typedef enum ResultCArrayFieldElement_Tag {
  OkCArrayFieldElement,
  ErrCArrayFieldElement,
} ResultCArrayFieldElement_Tag;

typedef struct ResultCArrayFieldElement {
  ResultCArrayFieldElement_Tag tag;
  union {
    struct {
      struct CArrayFieldElement ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultCArrayFieldElement;

typedef enum Resultc_char_Tag {
  Okc_char,
  Errc_char,
} Resultc_char_Tag;

typedef struct Resultc_char {
  Resultc_char_Tag tag;
  union {
    struct {
      const char *ok;
    };
    struct {
      struct Error err;
    };
  };
} Resultc_char;

typedef enum ResultFieldElement_Tag {
  OkFieldElement,
  ErrFieldElement,
} ResultFieldElement_Tag;

typedef struct ResultFieldElement {
  ResultFieldElement_Tag tag;
  union {
    struct {
      struct FieldElement ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultFieldElement;

typedef struct Signature {
  /**
   * The `r` value of a signature
   */
  struct FieldElement r;
  /**
   * The `s` value of a signature
   */
  struct FieldElement s;
} Signature;

typedef enum ResultSignature_Tag {
  OkSignature,
  ErrSignature,
} ResultSignature_Tag;

typedef struct ResultSignature {
  ResultSignature_Tag tag;
  union {
    struct {
      struct Signature ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultSignature;

typedef enum ResultProvider_Tag {
  OkProvider,
  ErrProvider,
} ResultProvider_Tag;

typedef struct ResultProvider {
  ResultProvider_Tag tag;
  union {
    struct {
      struct Provider *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultProvider;

typedef enum ResultAccount_Tag {
  OkAccount,
  ErrAccount,
} ResultAccount_Tag;

typedef struct ResultAccount {
  ResultAccount_Tag tag;
  union {
    struct {
      struct Account *ok;
    };
    struct {
      struct Error err;
    };
  };
} ResultAccount;

typedef struct Call {
  struct FieldElement to;
  const char *selector;
  struct CArrayFieldElement calldata;
} Call;

/**
 * Block hash, number or tag
 */
typedef enum BlockId_Tag {
  Hash,
  Number,
  BlockTag_,
} BlockId_Tag;

typedef struct BlockId {
  BlockId_Tag tag;
  union {
    struct {
      struct FieldElement hash;
    };
    struct {
      uint64_t number;
    };
    struct {
      enum BlockTag block_tag;
    };
  };
} BlockId;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a new Torii client instance
 *
 * # Parameters
 * * `torii_url` - URL of the Torii server
 * * `rpc_url` - URL of the Starknet RPC endpoint
 * * `libp2p_relay_url` - URL of the libp2p relay server
 * * `world` - World address as a FieldElement
 *
 * # Returns
 * Result containing pointer to new ToriiClient instance or error
 */
struct ResultToriiClient client_new(const char *torii_url,
                                    const char *rpc_url,
                                    const char *libp2p_relay_url,
                                    struct FieldElement world);

/**
 * Sets a logger callback function for the client
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `logger` - Callback function that takes a C string parameter
 */
void client_set_logger(struct ToriiClient *client, void (*logger)(const char*));

/**
 * Publishes a message to the network
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `message` - JSON string containing typed data message
 * * `signature_felts` - Array of field elements containing signature
 * * `signature_felts_len` - Length of signature array
 *
 * # Returns
 * Result containing byte array or error
 */
struct ResultCArrayu8 client_publish_message(struct ToriiClient *client,
                                             const char *message,
                                             const struct FieldElement *signature_felts,
                                             uintptr_t signature_felts_len);

/**
 * Queries entities matching given criteria
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `query` - Query parameters
 *
 * # Returns
 * Result containing array of matching entities or error
 */
struct ResultCArrayEntity client_entities(struct ToriiClient *client, const struct Query *query);

/**
 * Retrieves event messages matching the given query
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `query` - Query parameters
 * * `historical` - Whether to include historical messages
 *
 * # Returns
 * Result containing array of matching event message entities or error
 */
struct ResultCArrayEntity client_event_messages(struct ToriiClient *client,
                                                const struct Query *query,
                                                bool historical);

/**
 * Gets the world metadata for the client
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 *
 * # Returns
 * WorldMetadata structure containing world information
 */
struct WorldMetadata client_metadata(struct ToriiClient *client);

/**
 * Subscribes to entity state updates
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `clauses` - Array of entity key clauses to filter updates
 * * `clauses_len` - Length of clauses array
 * * `callback` - Function called when updates occur
 *
 * # Returns
 * Result containing pointer to Subscription or error
 */
struct ResultSubscription client_on_entity_state_update(struct ToriiClient *client,
                                                        const struct EntityKeysClause *clauses,
                                                        uintptr_t clauses_len,
                                                        void (*callback)(struct FieldElement,
                                                                         struct CArrayStruct));

/**
 * Updates an existing entity subscription with new clauses
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `subscription` - Pointer to existing Subscription
 * * `clauses` - New array of entity key clauses
 * * `clauses_len` - Length of new clauses array
 *
 * # Returns
 * Result containing success boolean or error
 */
struct Resultbool client_update_entity_subscription(struct ToriiClient *client,
                                                    struct Subscription *subscription,
                                                    const struct EntityKeysClause *clauses,
                                                    uintptr_t clauses_len);

/**
 * Subscribes to event message updates
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `clauses` - Array of entity key clauses to filter updates
 * * `clauses_len` - Length of clauses array
 * * `historical` - Whether to include historical messages
 * * `callback` - Function called when updates occur
 *
 * # Returns
 * Result containing pointer to Subscription or error
 */
struct ResultSubscription client_on_event_message_update(struct ToriiClient *client,
                                                         const struct EntityKeysClause *clauses,
                                                         uintptr_t clauses_len,
                                                         bool historical,
                                                         void (*callback)(struct FieldElement,
                                                                          struct CArrayStruct));

/**
 * Updates an existing event message subscription
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `subscription` - Pointer to existing Subscription
 * * `clauses` - New array of entity key clauses
 * * `clauses_len` - Length of new clauses array
 * * `historical` - Whether to include historical messages
 *
 * # Returns
 * Result containing success boolean or error
 */
struct Resultbool client_update_event_message_subscription(struct ToriiClient *client,
                                                           struct Subscription *subscription,
                                                           const struct EntityKeysClause *clauses,
                                                           uintptr_t clauses_len,
                                                           bool historical);

/**
 * Subscribes to Starknet events
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `clauses` - Array of entity key clauses to filter events
 * * `clauses_len` - Length of clauses array
 * * `callback` - Function called when events occur
 *
 * # Returns
 * Result containing pointer to Subscription or error
 */
struct ResultSubscription client_on_starknet_event(struct ToriiClient *client,
                                                   const struct EntityKeysClause *clauses,
                                                   uintptr_t clauses_len,
                                                   void (*callback)(struct Event));

/**
 * Retrieves token information for given contract addresses
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `contract_addresses` - Array of contract addresses
 * * `contract_addresses_len` - Length of addresses array
 *
 * # Returns
 * Result containing array of Token information or error
 */
struct ResultCArrayToken client_tokens(struct ToriiClient *client,
                                       const struct FieldElement *contract_addresses,
                                       uintptr_t contract_addresses_len);

/**
 * Gets token balances for given accounts and contracts
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `account_addresses` - Array of account addresses
 * * `account_addresses_len` - Length of account addresses array
 * * `contract_addresses` - Array of contract addresses
 * * `contract_addresses_len` - Length of contract addresses array
 *
 * # Returns
 * Result containing array of TokenBalance information or error
 */
struct ResultCArrayTokenBalance client_token_balances(struct ToriiClient *client,
                                                      const struct FieldElement *account_addresses,
                                                      uintptr_t account_addresses_len,
                                                      const struct FieldElement *contract_addresses,
                                                      uintptr_t contract_addresses_len);

/**
 * Subscribes to indexer updates
 *
 * # Parameters
 * * `client` - Pointer to ToriiClient instance
 * * `contract_address` - Optional contract address to filter updates
 * * `callback` - Function called when updates occur
 *
 * # Returns
 * Result containing pointer to Subscription or error
 */
struct ResultSubscription on_indexer_update(struct ToriiClient *client,
                                            const struct FieldElement *contract_address,
                                            void (*callback)(struct IndexerUpdate));

/**
 * Serializes a string into a byte array
 *
 * # Parameters
 * * `str` - String to serialize
 *
 * # Returns
 * Result containing array of FieldElements or error
 */
struct ResultCArrayFieldElement bytearray_serialize(const char *str);

/**
 * Deserializes field elements into a string
 *
 * # Parameters
 * * `felts` - Array of field elements
 * * `felts_len` - Length of field elements array
 *
 * # Returns
 * Result containing pointer to C string or error
 */
struct Resultc_char bytearray_deserialize(const struct FieldElement *felts, uintptr_t felts_len);

/**
 * Computes Poseidon hash of field elements
 *
 * # Parameters
 * * `felts` - Array of field elements
 * * `felts_len` - Length of array
 *
 * # Returns
 * FieldElement containing the hash result
 */
struct FieldElement poseidon_hash(const struct FieldElement *felts, uintptr_t felts_len);

/**
 * Gets selector from name string
 *
 * # Parameters
 * * `name` - Name to compute selector from
 *
 * # Returns
 * Result containing FieldElement selector or error
 */
struct ResultFieldElement get_selector_from_name(const char *name);

/**
 * Gets selector from tag string
 *
 * # Parameters
 * * `tag` - Tag to compute selector from
 *
 * # Returns
 * FieldElement containing the computed selector
 */
struct FieldElement get_selector_from_tag(const char *tag);

/**
 * Computes Starknet keccak hash of bytes
 *
 * # Parameters
 * * `bytes` - Byte array to hash
 * * `bytes_len` - Length of byte array
 *
 * # Returns
 * FieldElement containing the hash result
 */
struct FieldElement starknet_keccak(const uint8_t *bytes, uintptr_t bytes_len);

/**
 * Converts a short string to field element
 *
 * # Parameters
 * * `str` - String to convert
 *
 * # Returns
 * Result containing FieldElement or error
 */
struct ResultFieldElement cairo_short_string_to_felt(const char *str);

/**
 * Parses a field element into a short string
 *
 * # Parameters
 * * `felt` - FieldElement to parse
 *
 * # Returns
 * Result containing pointer to C string or error
 */
struct Resultc_char parse_cairo_short_string(struct FieldElement felt);

/**
 * Encodes typed data
 *
 * # Parameters
 * * `typed_data` - JSON string of typed data
 * * `address` - Address as FieldElement
 *
 * # Returns
 * Result containing encoded FieldElement or error
 */
struct ResultFieldElement typed_data_encode(const char *typed_data, struct FieldElement address);

/**
 * Generates a new signing key
 *
 * # Returns
 * FieldElement containing the new private key
 */
struct FieldElement signing_key_new(void);

/**
 * Signs a hash with a private key
 *
 * # Parameters
 * * `private_key` - Private key as FieldElement
 * * `hash` - Hash to sign as FieldElement
 *
 * # Returns
 * Result containing Signature or error
 */
struct ResultSignature signing_key_sign(struct FieldElement private_key, struct FieldElement hash);

/**
 * Creates a verifying key from a signing key
 *
 * # Parameters
 * * `signing_key` - Signing key as FieldElement
 *
 * # Returns
 * FieldElement containing the verifying key
 */
struct FieldElement verifying_key_new(struct FieldElement signing_key);

/**
 * Verifies a signature
 *
 * # Parameters
 * * `verifying_key` - Verifying key as FieldElement
 * * `hash` - Hash that was signed
 * * `signature` - Signature to verify
 *
 * # Returns
 * Result containing verification success boolean or error
 */
struct Resultbool verifying_key_verify(struct FieldElement verifying_key,
                                       struct FieldElement hash,
                                       struct Signature signature);

/**
 * Creates a new provider instance
 *
 * # Parameters
 * * `rpc_url` - URL of the RPC endpoint
 *
 * # Returns
 * Result containing pointer to Provider or error
 */
struct ResultProvider provider_new(const char *rpc_url);

/**
 * Creates a new account instance
 *
 * # Parameters
 * * `rpc` - Pointer to Provider
 * * `private_key` - Private key as FieldElement
 * * `address` - Account address as string
 *
 * # Returns
 * Result containing pointer to Account or error
 */
struct ResultAccount account_new(struct Provider *rpc,
                                 struct FieldElement private_key,
                                 const char *address);

/**
 * Makes a Starknet call
 *
 * # Parameters
 * * `provider` - Pointer to Provider
 * * `call` - Call parameters
 * * `block_id` - Block identifier
 *
 * # Returns
 * Result containing array of FieldElements or error
 */
struct ResultCArrayFieldElement starknet_call(struct Provider *provider,
                                              struct Call call,
                                              struct BlockId block_id);

/**
 * Deploys a burner account
 *
 * # Parameters
 * * `provider` - Pointer to Provider
 * * `master_account` - Pointer to master Account
 * * `signing_key` - Signing key for new account
 *
 * # Returns
 * Result containing pointer to new Account or error
 */
struct ResultAccount account_deploy_burner(struct Provider *provider,
                                           struct Account *master_account,
                                           struct FieldElement signing_key);

/**
 * Gets account address
 *
 * # Parameters
 * * `account` - Pointer to Account
 *
 * # Returns
 * FieldElement containing the account address
 */
struct FieldElement account_address(struct Account *account);

/**
 * Gets account chain ID
 *
 * # Parameters
 * * `account` - Pointer to Account
 *
 * # Returns
 * FieldElement containing the chain ID
 */
struct FieldElement account_chain_id(struct Account *account);

/**
 * Sets block ID for account
 *
 * # Parameters
 * * `account` - Pointer to Account
 * * `block_id` - New block ID
 */
void account_set_block_id(struct Account *account, struct BlockId block_id);

/**
 * Gets account nonce
 *
 * # Parameters
 * * `account` - Pointer to Account
 *
 * # Returns
 * Result containing FieldElement nonce or error
 */
struct ResultFieldElement account_nonce(struct Account *account);

/**
 * Executes raw transaction
 *
 * # Parameters
 * * `account` - Pointer to Account
 * * `calldata` - Array of Call structs
 * * `calldata_len` - Length of calldata array
 *
 * # Returns
 * Result containing transaction hash as FieldElement or error
 */
struct ResultFieldElement account_execute_raw(struct Account *account,
                                              const struct Call *calldata,
                                              uintptr_t calldata_len);

/**
 * Waits for transaction completion
 *
 * # Parameters
 * * `rpc` - Pointer to Provider
 * * `txn_hash` - Transaction hash as FieldElement
 *
 * # Returns
 * Result containing success boolean or error
 */
struct Resultbool wait_for_transaction(struct Provider *rpc, struct FieldElement txn_hash);

/**
 * Computes contract address
 *
 * # Parameters
 * * `class_hash` - Class hash as FieldElement
 * * `salt` - Salt as FieldElement
 * * `constructor_calldata` - Array of constructor parameters
 * * `constructor_calldata_len` - Length of constructor parameters
 * * `deployer_address` - Deployer address as FieldElement
 *
 * # Returns
 * FieldElement containing computed contract address
 */
struct FieldElement hash_get_contract_address(struct FieldElement class_hash,
                                              struct FieldElement salt,
                                              const struct FieldElement *constructor_calldata,
                                              uintptr_t constructor_calldata_len,
                                              struct FieldElement deployer_address);

/**
 * Cancels a subscription
 *
 * # Parameters
 * * `subscription` - Pointer to Subscription to cancel
 */
void subscription_cancel(struct Subscription *subscription);

/**
 * Frees a ToriiClient instance
 *
 * # Parameters
 * * `t` - Pointer to ToriiClient to free
 */
void client_free(struct ToriiClient *t);

/**
 * Frees a Provider instance
 *
 * # Parameters
 * * `rpc` - Pointer to Provider to free
 */
void provider_free(struct Provider *rpc);

/**
 * Frees a Model instance
 *
 * # Parameters
 * * `model` - Pointer to Model to free
 */
void model_free(struct Struct *model);

/**
 * Frees an Account instance
 *
 * # Parameters
 * * `account` - Pointer to Account to free
 */
void account_free(struct Account *account);

/**
 * Frees a Type instance
 *
 * # Parameters
 * * `ty` - Pointer to Type to free
 */
void ty_free(struct Ty *ty);

/**
 * Frees an Entity instance
 *
 * # Parameters
 * * `entity` - Pointer to Entity to free
 */
void entity_free(struct Entity *entity);

/**
 * Frees an Error instance
 *
 * # Parameters
 * * `error` - Pointer to Error to free
 */
void error_free(struct Error *error);

/**
 * Frees a WorldMetadata instance
 *
 * # Parameters
 * * `metadata` - Pointer to WorldMetadata to free
 */
void world_metadata_free(struct WorldMetadata *metadata);

/**
 * Frees a CArray instance
 *
 * # Parameters
 * * `data` - Pointer to array data
 * * `data_len` - Length of array
 */
void carray_free(void *data, uintptr_t data_len);

/**
 * Frees a string
 *
 * # Parameters
 * * `string` - Pointer to string to free
 */
void string_free(char *string);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
