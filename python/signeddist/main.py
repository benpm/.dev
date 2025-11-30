'''int QuadTree::dist(const sf::Vector2i& pos) const {
    int dx = std::max(std::max(NWcorner.x - pos.x, pos.x - SEcorner.x), 0);
    int dy = std::max(std::max(NWcorner.y - pos.y, pos.y - SEcorner.y), 0);
    return dx*dx + dy*dy;
}'''

import math

def dist(pos, nw_corner, se_corner):
  dx = max(nw_corner[0] - pos[0], pos[0] - se_corner[0], 0)
  dy = max(nw_corner[1] - pos[1], pos[1] - se_corner[1], 0)
  return math.sqrt(dx**2 + dy**2)
