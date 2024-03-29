#ifndef _SCENE_H_
#define _SCENE_H_

#include "model.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** Representation for a whole scene, a collection of models. */
typedef struct {
  /** Number of models in the scene. */
  int mCount;
  
  /** Capacity of the model list. */
  int mCap;

  /** List of pointers to models. */
  Model **mList;
} Scene;


/**
 * Frees a scene
 * @param scene the scene to free
 */
void freeScene(Scene *s);

/**
 * Applies to a transformation to a model in the scene given the name of the model
 * @param s the scene to apply the transformation to
 * @param name the name of the model to apply the transformation to
 * @param f the transformation function to apply
 * @param a the x value of transformation
 * @param b the y value of transformation
 * @returns true if the model was found
 */
bool applyToScene(Scene *s, char const *name, void (*f)(double pt[2], double a, double b),
                                                                      double a, double b);

/**
 * Checks the scene to see if it has a model with the specified name
 * @param s the scene to check
 * @param name the name of the model to check for
 * @return true if the model is found
 */
bool checkScene(Scene *s, const char * name);

#endif
