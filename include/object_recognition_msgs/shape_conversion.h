/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef SHAPE_CONVERSION_H_
#define SHAPE_CONVERSION_H_

#include <arm_navigation_msgs/Shape.h>
#include <shape_msgs/Mesh.h>
#include <shape_msgs/MeshTriangle.h>

/** Converts a shape_msgs::Mesh to an  arm_navigation_msgs::Shape that is a mesh
 */
inline arm_navigation_msgs::Shape
mesh_to_an_shape(const shape_msgs::Mesh & mesh)
{
  arm_navigation_msgs::Shape an_shape;
  an_shape.type = arm_navigation_msgs::Shape::MESH;
  an_shape.vertices = mesh.vertices;
  for(int tri_i=0; tri_i < mesh.triangles.size(); tri_i++)
    {
      an_shape.triangles.push_back(mesh.triangles[tri_i].vertex_indices[0]);
      an_shape.triangles.push_back(mesh.triangles[tri_i].vertex_indices[1]);
      an_shape.triangles.push_back(mesh.triangles[tri_i].vertex_indices[2]);
    }
  an_shape.__connection_header = mesh.__connection_header;

  return an_shape;
}

/** Converts an arm_navigation_msgs::Shape that is a mesh to a shape_msgs::Mesh
 */
inline shape_msgs::Mesh
an_shape_to_mesh(const arm_navigation_msgs::Shape & an_shape)
{
  shape_msgs::Mesh mesh;
  assert(an_shape.type == arm_navigation_msgs::Shape::MESH);
  mesh.vertices = an_shape.vertices;
  mesh.triangles.reserve(an_shape.triangles.size());
  shape_msgs::MeshTriangle triangle;
  for(int tri_i=0; tri_i < an_shape.triangles.size(); tri_i=tri_i+3)
    {
      triangle.vertex_indices[0] = an_shape.triangles[tri_i];
      triangle.vertex_indices[1] = an_shape.triangles[tri_i+1];
      triangle.vertex_indices[2] = an_shape.triangles[tri_i+2];
      mesh.triangles.push_back(triangle);
    }
  mesh.__connection_header = an_shape.__connection_header;

  return mesh;
}

#endif /* SHAPE_CONVERSION_H_ */
