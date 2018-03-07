
/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef ANNOUNCEPRESENCE_HPP
#define ANNOUNCEPRESENCE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API AnnouncePresence {
    public:
        AnnouncePresence() = default;
        AnnouncePresence(const AnnouncePresence&) = default;
        AnnouncePresence& operator=(const AnnouncePresence&) = default;
        AnnouncePresence(AnnouncePresence&&) noexcept = default; // NOLINT
        AnnouncePresence& operator=(AnnouncePresence&&) noexcept = default; // NOLINT
        ~AnnouncePresence() = default;

    public:
        static uint32_t ID();
        static const std::string ShortName();
        static const std::string LongName();
        
        AnnouncePresence& vehicleIp(const std::string &v) noexcept;
        std::string vehicleIp() const noexcept;
        
        AnnouncePresence& activePort(const uint16_t &v) noexcept;
        uint16_t activePort() const noexcept;
        

        template<class Visitor>
        void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            
            doVisit(1, std::move("std::string"s), std::move("vehicleIp"s), m_vehicleIp, visitor);
            
            doVisit(2, std::move("uint16_t"s), std::move("activePort"s), m_activePort, visitor);
            
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            
            doTripletForwardVisit(1, std::move("std::string"s), std::move("vehicleIp"s), m_vehicleIp, preVisit, visit, postVisit);
            
            doTripletForwardVisit(2, std::move("uint16_t"s), std::move("activePort"s), m_activePort, preVisit, visit, postVisit);
            
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        
        std::string m_vehicleIp{ ""s }; // field identifier = 1.
        
        uint16_t m_activePort{ 0 }; // field identifier = 2.
        
};


template<>
struct isVisitable<AnnouncePresence> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<AnnouncePresence> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef FOLLOWREQUEST_HPP
#define FOLLOWREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API FollowRequest {
    public:
        FollowRequest() = default;
        FollowRequest(const FollowRequest&) = default;
        FollowRequest& operator=(const FollowRequest&) = default;
        FollowRequest(FollowRequest&&) noexcept = default; // NOLINT
        FollowRequest& operator=(FollowRequest&&) noexcept = default; // NOLINT
        ~FollowRequest() = default;

    public:
        static uint32_t ID();
        static const std::string ShortName();
        static const std::string LongName();
        

        template<class Visitor>
        void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        
};


template<>
struct isVisitable<FollowRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<FollowRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef FOLLOWRESPONSE_HPP
#define FOLLOWRESPONSE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API FollowResponse {
    public:
        FollowResponse() = default;
        FollowResponse(const FollowResponse&) = default;
        FollowResponse& operator=(const FollowResponse&) = default;
        FollowResponse(FollowResponse&&) noexcept = default; // NOLINT
        FollowResponse& operator=(FollowResponse&&) noexcept = default; // NOLINT
        ~FollowResponse() = default;

    public:
        static uint32_t ID();
        static const std::string ShortName();
        static const std::string LongName();
        
        FollowResponse& ntpServerIp(const std::string &v) noexcept;
        std::string ntpServerIp() const noexcept;
        

        template<class Visitor>
        void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            
            doVisit(2, std::move("std::string"s), std::move("ntpServerIp"s), m_ntpServerIp, visitor);
            
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            
            doTripletForwardVisit(2, std::move("std::string"s), std::move("ntpServerIp"s), m_ntpServerIp, preVisit, visit, postVisit);
            
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        
        std::string m_ntpServerIp{ ""s }; // field identifier = 2.
        
};


template<>
struct isVisitable<FollowResponse> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<FollowResponse> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef STOPFOLLOW_HPP
#define STOPFOLLOW_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API StopFollow {
    public:
        StopFollow() = default;
        StopFollow(const StopFollow&) = default;
        StopFollow& operator=(const StopFollow&) = default;
        StopFollow(StopFollow&&) noexcept = default; // NOLINT
        StopFollow& operator=(StopFollow&&) noexcept = default; // NOLINT
        ~StopFollow() = default;

    public:
        static uint32_t ID();
        static const std::string ShortName();
        static const std::string LongName();
        

        template<class Visitor>
        void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        
};


template<>
struct isVisitable<StopFollow> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<StopFollow> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef LEADERSTATUS_HPP
#define LEADERSTATUS_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API LeaderStatus {
    public:
        LeaderStatus() = default;
        LeaderStatus(const LeaderStatus&) = default;
        LeaderStatus& operator=(const LeaderStatus&) = default;
        LeaderStatus(LeaderStatus&&) noexcept = default; // NOLINT
        LeaderStatus& operator=(LeaderStatus&&) noexcept = default; // NOLINT
        ~LeaderStatus() = default;

    public:
        static uint32_t ID();
        static const std::string ShortName();
        static const std::string LongName();
        
        LeaderStatus& timestamp(const uint32_t &v) noexcept;
        uint32_t timestamp() const noexcept;
        
        LeaderStatus& speed(const uint8_t &v) noexcept;
        uint8_t speed() const noexcept;
        
        LeaderStatus& steeringAngle(const uint8_t &v) noexcept;
        uint8_t steeringAngle() const noexcept;
        
        LeaderStatus& distanceTraveled(const uint8_t &v) noexcept;
        uint8_t distanceTraveled() const noexcept;
        

        template<class Visitor>
        void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            
            doVisit(1, std::move("uint32_t"s), std::move("timestamp"s), m_timestamp, visitor);
            
            doVisit(2, std::move("uint8_t"s), std::move("speed"s), m_speed, visitor);
            
            doVisit(3, std::move("uint8_t"s), std::move("steeringAngle"s), m_steeringAngle, visitor);
            
            doVisit(4, std::move("uint8_t"s), std::move("distanceTraveled"s), m_distanceTraveled, visitor);
            
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("timestamp"s), m_timestamp, preVisit, visit, postVisit);
            
            doTripletForwardVisit(2, std::move("uint8_t"s), std::move("speed"s), m_speed, preVisit, visit, postVisit);
            
            doTripletForwardVisit(3, std::move("uint8_t"s), std::move("steeringAngle"s), m_steeringAngle, preVisit, visit, postVisit);
            
            doTripletForwardVisit(4, std::move("uint8_t"s), std::move("distanceTraveled"s), m_distanceTraveled, preVisit, visit, postVisit);
            
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        
        uint32_t m_timestamp{ 0 }; // field identifier = 1.
        
        uint8_t m_speed{ 0 }; // field identifier = 2.
        
        uint8_t m_steeringAngle{ 0 }; // field identifier = 3.
        
        uint8_t m_distanceTraveled{ 0 }; // field identifier = 4.
        
};


template<>
struct isVisitable<LeaderStatus> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<LeaderStatus> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef FOLLOWERSTATUS_HPP
#define FOLLOWERSTATUS_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>

using namespace std::string_literals; // NOLINT
class LIB_API FollowerStatus {
    public:
        FollowerStatus() = default;
        FollowerStatus(const FollowerStatus&) = default;
        FollowerStatus& operator=(const FollowerStatus&) = default;
        FollowerStatus(FollowerStatus&&) noexcept = default; // NOLINT
        FollowerStatus& operator=(FollowerStatus&&) noexcept = default; // NOLINT
        ~FollowerStatus() = default;

    public:
        static uint32_t ID();
        static const std::string ShortName();
        static const std::string LongName();
        
        FollowerStatus& timestamp(const uint32_t &v) noexcept;
        uint32_t timestamp() const noexcept;
        
        FollowerStatus& speed(const uint8_t &v) noexcept;
        uint8_t speed() const noexcept;
        
        FollowerStatus& steeringAngle(const uint8_t &v) noexcept;
        uint8_t steeringAngle() const noexcept;
        
        FollowerStatus& distanceFront(const uint8_t &v) noexcept;
        uint8_t distanceFront() const noexcept;
        
        FollowerStatus& distanceTraveled(const uint8_t &v) noexcept;
        uint8_t distanceTraveled() const noexcept;
        

        template<class Visitor>
        void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            
            doVisit(1, std::move("uint32_t"s), std::move("timestamp"s), m_timestamp, visitor);
            
            doVisit(2, std::move("uint8_t"s), std::move("speed"s), m_speed, visitor);
            
            doVisit(3, std::move("uint8_t"s), std::move("steeringAngle"s), m_steeringAngle, visitor);
            
            doVisit(4, std::move("uint8_t"s), std::move("distanceFront"s), m_distanceFront, visitor);
            
            doVisit(5, std::move("uint8_t"s), std::move("distanceTraveled"s), m_distanceTraveled, visitor);
            
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("timestamp"s), m_timestamp, preVisit, visit, postVisit);
            
            doTripletForwardVisit(2, std::move("uint8_t"s), std::move("speed"s), m_speed, preVisit, visit, postVisit);
            
            doTripletForwardVisit(3, std::move("uint8_t"s), std::move("steeringAngle"s), m_steeringAngle, preVisit, visit, postVisit);
            
            doTripletForwardVisit(4, std::move("uint8_t"s), std::move("distanceFront"s), m_distanceFront, preVisit, visit, postVisit);
            
            doTripletForwardVisit(5, std::move("uint8_t"s), std::move("distanceTraveled"s), m_distanceTraveled, preVisit, visit, postVisit);
            
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        
        uint32_t m_timestamp{ 0 }; // field identifier = 1.
        
        uint8_t m_speed{ 0 }; // field identifier = 2.
        
        uint8_t m_steeringAngle{ 0 }; // field identifier = 3.
        
        uint8_t m_distanceFront{ 0 }; // field identifier = 4.
        
        uint8_t m_distanceTraveled{ 0 }; // field identifier = 5.
        
};


template<>
struct isVisitable<FollowerStatus> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<FollowerStatus> {
    static const bool value = true;
};
#endif

