// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: person.proto

#ifndef PROTOBUF_INCLUDED_person_2eproto
#define PROTOBUF_INCLUDED_person_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_person_2eproto 

namespace protobuf_person_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_person_2eproto
namespace db {
class tb_Person;
class tb_PersonDefaultTypeInternal;
extern tb_PersonDefaultTypeInternal _tb_Person_default_instance_;
}  // namespace db
namespace google {
namespace protobuf {
template<> ::db::tb_Person* Arena::CreateMaybeMessage<::db::tb_Person>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace db {

enum MSGID {
  MSGID_default = 0,
  MSGID_tb_Person = 1004,
  MSGID_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MSGID_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MSGID_IsValid(int value);
const MSGID MSGID_MIN = MSGID_default;
const MSGID MSGID_MAX = MSGID_tb_Person;
const int MSGID_ARRAYSIZE = MSGID_MAX + 1;

const ::google::protobuf::EnumDescriptor* MSGID_descriptor();
inline const ::std::string& MSGID_Name(MSGID value) {
  return ::google::protobuf::internal::NameOfEnum(
    MSGID_descriptor(), value);
}
inline bool MSGID_Parse(
    const ::std::string& name, MSGID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MSGID>(
    MSGID_descriptor(), name, value);
}
enum PhoneType {
  MOBILE = 0,
  HOME = 1,
  WORK = 2,
  PhoneType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  PhoneType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool PhoneType_IsValid(int value);
const PhoneType PhoneType_MIN = MOBILE;
const PhoneType PhoneType_MAX = WORK;
const int PhoneType_ARRAYSIZE = PhoneType_MAX + 1;

const ::google::protobuf::EnumDescriptor* PhoneType_descriptor();
inline const ::std::string& PhoneType_Name(PhoneType value) {
  return ::google::protobuf::internal::NameOfEnum(
    PhoneType_descriptor(), value);
}
inline bool PhoneType_Parse(
    const ::std::string& name, PhoneType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PhoneType>(
    PhoneType_descriptor(), name, value);
}
// ===================================================================

class tb_Person : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:db.tb_Person) */ {
 public:
  tb_Person();
  virtual ~tb_Person();

  tb_Person(const tb_Person& from);

  inline tb_Person& operator=(const tb_Person& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  tb_Person(tb_Person&& from) noexcept
    : tb_Person() {
    *this = ::std::move(from);
  }

  inline tb_Person& operator=(tb_Person&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const tb_Person& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const tb_Person* internal_default_instance() {
    return reinterpret_cast<const tb_Person*>(
               &_tb_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(tb_Person* other);
  friend void swap(tb_Person& a, tb_Person& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline tb_Person* New() const final {
    return CreateMaybeMessage<tb_Person>(NULL);
  }

  tb_Person* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<tb_Person>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const tb_Person& from);
  void MergeFrom(const tb_Person& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(tb_Person* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 3;
  void clear_name();
  static const int kNameFieldNumber = 3;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string email = 5;
  void clear_email();
  static const int kEmailFieldNumber = 5;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // bytes itemlist = 20;
  void clear_itemlist();
  static const int kItemlistFieldNumber = 20;
  const ::std::string& itemlist() const;
  void set_itemlist(const ::std::string& value);
  #if LANG_CXX11
  void set_itemlist(::std::string&& value);
  #endif
  void set_itemlist(const char* value);
  void set_itemlist(const void* value, size_t size);
  ::std::string* mutable_itemlist();
  ::std::string* release_itemlist();
  void set_allocated_itemlist(::std::string* itemlist);

  // bytes equiplist = 21;
  void clear_equiplist();
  static const int kEquiplistFieldNumber = 21;
  const ::std::string& equiplist() const;
  void set_equiplist(const ::std::string& value);
  #if LANG_CXX11
  void set_equiplist(::std::string&& value);
  #endif
  void set_equiplist(const char* value);
  void set_equiplist(const void* value, size_t size);
  ::std::string* mutable_equiplist();
  ::std::string* release_equiplist();
  void set_allocated_equiplist(::std::string* equiplist);

  // bytes tasklist = 22;
  void clear_tasklist();
  static const int kTasklistFieldNumber = 22;
  const ::std::string& tasklist() const;
  void set_tasklist(const ::std::string& value);
  #if LANG_CXX11
  void set_tasklist(::std::string&& value);
  #endif
  void set_tasklist(const char* value);
  void set_tasklist(const void* value, size_t size);
  ::std::string* mutable_tasklist();
  ::std::string* release_tasklist();
  void set_allocated_tasklist(::std::string* tasklist);

  // bytes skilllist = 23;
  void clear_skilllist();
  static const int kSkilllistFieldNumber = 23;
  const ::std::string& skilllist() const;
  void set_skilllist(const ::std::string& value);
  #if LANG_CXX11
  void set_skilllist(::std::string&& value);
  #endif
  void set_skilllist(const char* value);
  void set_skilllist(const void* value, size_t size);
  ::std::string* mutable_skilllist();
  ::std::string* release_skilllist();
  void set_allocated_skilllist(::std::string* skilllist);

  // uint64 uuid = 1;
  void clear_uuid();
  static const int kUuidFieldNumber = 1;
  ::google::protobuf::uint64 uuid() const;
  void set_uuid(::google::protobuf::uint64 value);

  // uint64 number = 4;
  void clear_number();
  static const int kNumberFieldNumber = 4;
  ::google::protobuf::uint64 number() const;
  void set_number(::google::protobuf::uint64 value);

  // int32 job = 2;
  void clear_job();
  static const int kJobFieldNumber = 2;
  ::google::protobuf::int32 job() const;
  void set_job(::google::protobuf::int32 value);

  // .db.PhoneType phonetype = 6;
  void clear_phonetype();
  static const int kPhonetypeFieldNumber = 6;
  ::db::PhoneType phonetype() const;
  void set_phonetype(::db::PhoneType value);

  // double money = 7;
  void clear_money();
  static const int kMoneyFieldNumber = 7;
  double money() const;
  void set_money(double value);

  // float cash = 8;
  void clear_cash();
  static const int kCashFieldNumber = 8;
  float cash() const;
  void set_cash(float value);

  // @@protoc_insertion_point(class_scope:db.tb_Person)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  ::google::protobuf::internal::ArenaStringPtr itemlist_;
  ::google::protobuf::internal::ArenaStringPtr equiplist_;
  ::google::protobuf::internal::ArenaStringPtr tasklist_;
  ::google::protobuf::internal::ArenaStringPtr skilllist_;
  ::google::protobuf::uint64 uuid_;
  ::google::protobuf::uint64 number_;
  ::google::protobuf::int32 job_;
  int phonetype_;
  double money_;
  float cash_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_person_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// tb_Person

// uint64 uuid = 1;
inline void tb_Person::clear_uuid() {
  uuid_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 tb_Person::uuid() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.uuid)
  return uuid_;
}
inline void tb_Person::set_uuid(::google::protobuf::uint64 value) {
  
  uuid_ = value;
  // @@protoc_insertion_point(field_set:db.tb_Person.uuid)
}

// int32 job = 2;
inline void tb_Person::clear_job() {
  job_ = 0;
}
inline ::google::protobuf::int32 tb_Person::job() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.job)
  return job_;
}
inline void tb_Person::set_job(::google::protobuf::int32 value) {
  
  job_ = value;
  // @@protoc_insertion_point(field_set:db.tb_Person.job)
}

// string name = 3;
inline void tb_Person::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& tb_Person::name() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.name)
  return name_.GetNoArena();
}
inline void tb_Person::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:db.tb_Person.name)
}
#if LANG_CXX11
inline void tb_Person::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:db.tb_Person.name)
}
#endif
inline void tb_Person::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:db.tb_Person.name)
}
inline void tb_Person::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:db.tb_Person.name)
}
inline ::std::string* tb_Person::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:db.tb_Person.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* tb_Person::release_name() {
  // @@protoc_insertion_point(field_release:db.tb_Person.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void tb_Person::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:db.tb_Person.name)
}

// uint64 number = 4;
inline void tb_Person::clear_number() {
  number_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 tb_Person::number() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.number)
  return number_;
}
inline void tb_Person::set_number(::google::protobuf::uint64 value) {
  
  number_ = value;
  // @@protoc_insertion_point(field_set:db.tb_Person.number)
}

// string email = 5;
inline void tb_Person::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& tb_Person::email() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.email)
  return email_.GetNoArena();
}
inline void tb_Person::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:db.tb_Person.email)
}
#if LANG_CXX11
inline void tb_Person::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:db.tb_Person.email)
}
#endif
inline void tb_Person::set_email(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:db.tb_Person.email)
}
inline void tb_Person::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:db.tb_Person.email)
}
inline ::std::string* tb_Person::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:db.tb_Person.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* tb_Person::release_email() {
  // @@protoc_insertion_point(field_release:db.tb_Person.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void tb_Person::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:db.tb_Person.email)
}

// .db.PhoneType phonetype = 6;
inline void tb_Person::clear_phonetype() {
  phonetype_ = 0;
}
inline ::db::PhoneType tb_Person::phonetype() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.phonetype)
  return static_cast< ::db::PhoneType >(phonetype_);
}
inline void tb_Person::set_phonetype(::db::PhoneType value) {
  
  phonetype_ = value;
  // @@protoc_insertion_point(field_set:db.tb_Person.phonetype)
}

// double money = 7;
inline void tb_Person::clear_money() {
  money_ = 0;
}
inline double tb_Person::money() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.money)
  return money_;
}
inline void tb_Person::set_money(double value) {
  
  money_ = value;
  // @@protoc_insertion_point(field_set:db.tb_Person.money)
}

// float cash = 8;
inline void tb_Person::clear_cash() {
  cash_ = 0;
}
inline float tb_Person::cash() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.cash)
  return cash_;
}
inline void tb_Person::set_cash(float value) {
  
  cash_ = value;
  // @@protoc_insertion_point(field_set:db.tb_Person.cash)
}

// bytes itemlist = 20;
inline void tb_Person::clear_itemlist() {
  itemlist_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& tb_Person::itemlist() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.itemlist)
  return itemlist_.GetNoArena();
}
inline void tb_Person::set_itemlist(const ::std::string& value) {
  
  itemlist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:db.tb_Person.itemlist)
}
#if LANG_CXX11
inline void tb_Person::set_itemlist(::std::string&& value) {
  
  itemlist_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:db.tb_Person.itemlist)
}
#endif
inline void tb_Person::set_itemlist(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  itemlist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:db.tb_Person.itemlist)
}
inline void tb_Person::set_itemlist(const void* value, size_t size) {
  
  itemlist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:db.tb_Person.itemlist)
}
inline ::std::string* tb_Person::mutable_itemlist() {
  
  // @@protoc_insertion_point(field_mutable:db.tb_Person.itemlist)
  return itemlist_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* tb_Person::release_itemlist() {
  // @@protoc_insertion_point(field_release:db.tb_Person.itemlist)
  
  return itemlist_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void tb_Person::set_allocated_itemlist(::std::string* itemlist) {
  if (itemlist != NULL) {
    
  } else {
    
  }
  itemlist_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), itemlist);
  // @@protoc_insertion_point(field_set_allocated:db.tb_Person.itemlist)
}

// bytes equiplist = 21;
inline void tb_Person::clear_equiplist() {
  equiplist_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& tb_Person::equiplist() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.equiplist)
  return equiplist_.GetNoArena();
}
inline void tb_Person::set_equiplist(const ::std::string& value) {
  
  equiplist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:db.tb_Person.equiplist)
}
#if LANG_CXX11
inline void tb_Person::set_equiplist(::std::string&& value) {
  
  equiplist_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:db.tb_Person.equiplist)
}
#endif
inline void tb_Person::set_equiplist(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  equiplist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:db.tb_Person.equiplist)
}
inline void tb_Person::set_equiplist(const void* value, size_t size) {
  
  equiplist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:db.tb_Person.equiplist)
}
inline ::std::string* tb_Person::mutable_equiplist() {
  
  // @@protoc_insertion_point(field_mutable:db.tb_Person.equiplist)
  return equiplist_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* tb_Person::release_equiplist() {
  // @@protoc_insertion_point(field_release:db.tb_Person.equiplist)
  
  return equiplist_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void tb_Person::set_allocated_equiplist(::std::string* equiplist) {
  if (equiplist != NULL) {
    
  } else {
    
  }
  equiplist_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), equiplist);
  // @@protoc_insertion_point(field_set_allocated:db.tb_Person.equiplist)
}

// bytes tasklist = 22;
inline void tb_Person::clear_tasklist() {
  tasklist_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& tb_Person::tasklist() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.tasklist)
  return tasklist_.GetNoArena();
}
inline void tb_Person::set_tasklist(const ::std::string& value) {
  
  tasklist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:db.tb_Person.tasklist)
}
#if LANG_CXX11
inline void tb_Person::set_tasklist(::std::string&& value) {
  
  tasklist_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:db.tb_Person.tasklist)
}
#endif
inline void tb_Person::set_tasklist(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  tasklist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:db.tb_Person.tasklist)
}
inline void tb_Person::set_tasklist(const void* value, size_t size) {
  
  tasklist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:db.tb_Person.tasklist)
}
inline ::std::string* tb_Person::mutable_tasklist() {
  
  // @@protoc_insertion_point(field_mutable:db.tb_Person.tasklist)
  return tasklist_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* tb_Person::release_tasklist() {
  // @@protoc_insertion_point(field_release:db.tb_Person.tasklist)
  
  return tasklist_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void tb_Person::set_allocated_tasklist(::std::string* tasklist) {
  if (tasklist != NULL) {
    
  } else {
    
  }
  tasklist_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), tasklist);
  // @@protoc_insertion_point(field_set_allocated:db.tb_Person.tasklist)
}

// bytes skilllist = 23;
inline void tb_Person::clear_skilllist() {
  skilllist_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& tb_Person::skilllist() const {
  // @@protoc_insertion_point(field_get:db.tb_Person.skilllist)
  return skilllist_.GetNoArena();
}
inline void tb_Person::set_skilllist(const ::std::string& value) {
  
  skilllist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:db.tb_Person.skilllist)
}
#if LANG_CXX11
inline void tb_Person::set_skilllist(::std::string&& value) {
  
  skilllist_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:db.tb_Person.skilllist)
}
#endif
inline void tb_Person::set_skilllist(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  skilllist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:db.tb_Person.skilllist)
}
inline void tb_Person::set_skilllist(const void* value, size_t size) {
  
  skilllist_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:db.tb_Person.skilllist)
}
inline ::std::string* tb_Person::mutable_skilllist() {
  
  // @@protoc_insertion_point(field_mutable:db.tb_Person.skilllist)
  return skilllist_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* tb_Person::release_skilllist() {
  // @@protoc_insertion_point(field_release:db.tb_Person.skilllist)
  
  return skilllist_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void tb_Person::set_allocated_skilllist(::std::string* skilllist) {
  if (skilllist != NULL) {
    
  } else {
    
  }
  skilllist_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), skilllist);
  // @@protoc_insertion_point(field_set_allocated:db.tb_Person.skilllist)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace db

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::db::MSGID> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::db::MSGID>() {
  return ::db::MSGID_descriptor();
}
template <> struct is_proto_enum< ::db::PhoneType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::db::PhoneType>() {
  return ::db::PhoneType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_person_2eproto
