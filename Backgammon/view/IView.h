//
// Created by Rikki on 11/9/2017.
//

#ifndef BACKGAMMON_IVIEW_H
#define BACKGAMMON_IVIEW_H

/**
 * Represents an interface for a View for a Backgammon game.
 */
class IView {
public:
    // Outputs the m_view of the current Backgammon game.
    virtual void refresh() =0;
};

#endif //BACKGAMMON_IVIEW_H
