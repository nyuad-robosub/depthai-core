#pragma once

#include <depthai/pipeline/Node.hpp>

// shared
// TODO #include <depthai-shared/pb/properties/XLinkOutProperties.hpp>

namespace dai {
namespace node {

/**
 * @brief UVC (USB Video Class) node
 */
class UVC : public Node {
    //dai::XLinkOutProperties properties;

    std::string getName() const override;
    nlohmann::json getProperties() override;
    std::shared_ptr<Node> clone() override;

   public:
    UVC(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId);

    /**
     * Input for UVC node. Limited for now to 1920x1080, NV12 frame types
     */
    Input input{*this, "in", Input::Type::SReceiver, {{DatatypeEnum::Buffer, true}}};

};

}  // namespace node
}  // namespace dai
